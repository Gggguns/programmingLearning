#define _CRT_SECURE_NO_WARNINGS
#include "ThreadCache.h"
#include "CentralCache.h"


void* ThreadCache::Allocate(size_t size)
{
	//首先，判断申请是否小于254KB
	assert(size <= MAX_BYTES);
	//计算对齐数
	size_t alignSize = SizeClass::RoundUp(size);
	//找映射位置
	size_t index = SizeClass::Index(alignSize);

	//从链表中获取
	if (!_freeLists[index].Empty())
	{
		return _freeLists[index].Pop();
	}
	else
	{
		//链表为空，向central cache申请
		return FetchFromCentralCache(index, alignSize);
	}
}

void ThreadCache::DeAllocate(void* ptr, size_t size)
{
	assert(ptr);
	assert(size <= MAX_BYTES);

	//找对映射自由链表桶，插入进去
	size_t index = SizeClass::Index(size);
	_freeLists[index].Push(ptr);

	//当链表长度大于一次批量申请的内存时，就开始还一段list给central cache
	if (_freeLists[index].Size() >= _freeLists[index].MaxSize())
	{
		ListTooLong(_freeLists[index], size);
	}
}

void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	//如果说它申请一个，我们直接给它50个，它可能用不完，造成浪费。
	//慢开始反馈调节算法
	//1.最开始不会一次向central cache一次批量要太多，因为太多了可能用不完
	//2.如果你申请这个size大小内存需求，那么batch就会不断增长，直到上限
	//3.size越大，一次向central cache要的batch就越小
	//4.size越小，一次向central cache要的batch就越多
	//windowns中有一个min的宏和algorithm头文件里的min冲突了，我们优先使用宏，这样就不会报错了
	size_t batchNum = min(_freeLists[index].MaxSize(), SizeClass::NumMoveSize(size));

	if (_freeLists[index].MaxSize() == batchNum)
	{
		_freeLists[index].MaxSize() += 1;
	}

	//获取单例并申请内存
	void* start = nullptr;
	void* end = nullptr;

	//申请和实际得到的不一定相等
	size_t actualNum = CentralCache::GetInstance()->FetchRangeObj(start, end, batchNum, size);

	assert(actualNum > 0);

	if (actualNum == 1)
	{
		//只申请到一个，我们返回即可
		assert(start == end);
		return start;
	}
	else
	{
		//申请到多个小块内存，我们返回第一个，剩下的头插到链表中
		_freeLists[index].PushRange(NextObj(start), end, actualNum - 1);
		return start;
	}

}

void ThreadCache::ListTooLong(FreeList& list, size_t size)
{
	void* start = nullptr;
	void* end = nullptr;

	//取出一段链表进行回收
	list.PopRange(start,end,list.MaxSize());

	//归还至相应的span
	CentralCache::GetInstance()->ReleaseListToSpans(start, size);
}