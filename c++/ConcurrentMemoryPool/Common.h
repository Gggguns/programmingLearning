#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>
#include <cassert>
#include <algorithm>
#include <unordered_map>

//这里需要先判断_WIN64，64环境下既有_WIN32，也有_WIN64。32环境下，只有_WIN32
#ifdef _WIN64
	typedef unsigned long long PAGE_ID;
#elif _WIN32
	typedef size_t PAGE_ID;
#else
	//Linux
#endif


static const size_t MAX_BYTES = 254 * 1024;//thread cache的最大申请空间
static const size_t NFREELIST = 208;//thread cache和central cache的哈希桶个数
static const size_t NPAGES = 129;//page cache的哈希桶个数，把下标为零的位置空出来不用
static const size_t PAGE_SHIFT = 13;//一个页的大小

//操作系统有Windows和Linux两种，需要条件编译
#ifdef _WIN32
#include<windows.h>
#else
	//Linux环境
#endif

//直接去堆上，按页申请空间
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);//kpage << 13与kpage*8*1024等价
#else
	//Linux下 brk mmap等
#endif

	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}
}

static void*& NextObj(void* obj)
{
	return *(void**)obj;
}

//管理切分好的小对象的自由链表
class FreeList
{
public:
	void Push(void* obj) {
		assert(obj);
		//头插
		//*(void**)obj = _freeList;
		NextObj(obj) = _freeList;
		_freeList = obj;
		_size++;
	}
	
	void PushRange(void* start, void* end,size_t n)
	{
		//头插一段链表
		NextObj(end) = _freeList;
		_freeList = start;
		_size += n;
	}

	void PopRange(void*& start, void*& end, size_t n)
	{
		assert(n >= _size);
		start = _freeList;
		end = start;

		for (size_t i = 0;i < n - 1;i++)
		{
			end = NextObj(end);
		}

		_freeList = NextObj(end);
		NextObj(end) = nullptr;
		_size -= n;
	}

	void* Pop() {
		assert(_freeList);
		//头删
		void* obj = _freeList;
		//_freeList = *(void**)_freeList;
		_freeList = NextObj(obj);
		_size--;
		return obj;
	}
	//判空
	bool Empty()
	{
		return _freeList == nullptr;
	}
	size_t& MaxSize()
	{
		return _maxSize;
	}
	size_t Size()
	{
		return _size;
	}
private:
	void* _freeList = nullptr;
	size_t _maxSize = 1;
	size_t _size;
};

//计算对象大小的对齐映射规则
class SizeClass
{

	// 整体控制在最多10%左右的内碎片浪费
	// [1,128]					8byte对齐	    freelist[0,16)
	// [128+1,1024]				16byte对齐	    freelist[16,72)
	// [1024+1,8*1024]			128byte对齐	    freelist[72,128)
	// [8*1024+1,64*1024]		1024byte对齐     freelist[128,184)
	// [64*1024+1,256*1024]		8*1024byte对齐   freelist[184,208)
	
	//计算一个数对齐后的大小，比如你传125，则需返回128
	//第一个参数是申请空间大小，第二个是对齐数
	//size_t RoundUp(size_t size, size_t alignNum)
	//{
	//	size_t alignSize = 0;
	//	if (size % alignNum != 0)
	//	{
	//		//以size =7 和 alignNum = 8为例 答案是8 （7/8+1*8=8            
	//		alignSize = (size / alignNum + 1) * alignNum;
	//	}
	//	else
	//	{
	//		alignSize = size;
	//	}
	//	return alignSize;
	//}
public:
	//计算对齐数
	static inline size_t _RoundUp(size_t bytes, size_t alignNum)
	{
		//保留整数部分，删除余数部分
		return (bytes + alignNum - 1) & ~(alignNum - 1);
	}

	static inline size_t RoundUp(size_t size)
	{
		if (size <= 128)
		{
			return _RoundUp(size, 8);
		}
		else if (size <= 1024)
		{
			return _RoundUp(size, 16);
		}
		else if (size <= 8*1024)
		{
			return _RoundUp(size, 128);
		}
		else if (size <= 64 * 1024)
		{
			return _RoundUp(size, 1024);
		}
		else if (size <= 256 * 1024)
		{
			return _RoundUp(size, 8 * 1024);
		}
		else
		{
			assert(false);
		}
		return -1;
	}

	//Index的子函数
	static inline size_t _Index(size_t bytes, size_t align_shift) 
	{
		//怎么理解，和刚刚的RoundUp的原理有点类似
		//如果对齐数是8，也就是2的3次方，align_shift等于3
		//以align_shift=3为例，1 << align_shift，1向左移3位就是8
		//>>align_shift就是模上8的意思，带几个数进去你就理解了
		return ((bytes + (1 << align_shift) - 1) >> align_shift) - 1;
	}

	//计算映射到哪一个自由链表桶
	static inline size_t Index(size_t bytes)
	{
		//判定是否小于254KB
		assert(bytes <= MAX_BYTES);
		//根据一开始的规则，给出每个区间有多少个链
		static int group_array[] = { 16,56,56,56 };
		if (bytes <= 128)
		{
			return _Index(bytes, 3);
		}
		else if (bytes <= 1024)
		{
			//前面128字节是按8对齐
			return _Index(bytes - 128, 4) + group_array[0];
		}
		else if (bytes <= 8 * 1024)
		{
			return _Index(bytes - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (bytes <= 64*1024)
		{
			return _Index(bytes - 8 * 1024, 10) + group_array[2] + group_array[1] + group_array[0];
		}
		else if (bytes <= 256 * 1024)
		{
			return _Index(bytes - 64 * 1024, 13) + group_array[3] + group_array[2] + group_array[1] + group_array[0];
		}
		else
		{
			assert(false);
		}
		return -1;
	}

	//一次thread cache从中心缓存获取多少个
	static size_t NumMoveSize(size_t size)
	{
		if (size == 0)
			return 0;

		//[2,512]，一次批量移动多少个对象的（慢启动）的上限值
		//小对象一次批量上限高
		//小对象一次批量上限低
		int num = MAX_BYTES / size;
		if (num < 2)
			num = 2;

		if (num > 512)
			num = 512;

		return num;
	}

	//计算一次向系统获取几个页
	//单个对象 8byte
	//....
	//单个对象256KB
	static size_t NumMovePage(size_t size)
	{
		//计算要获取多少个
		size_t num = NumMoveSize(size);
		size_t npage = num * size;

		//除以一个页的大小
		npage >>= PAGE_SHIFT;//假设一个页的大小是8KB，也就是2的13次方，PAGE_SHIFT设置为13

		//不足一页，给一页
		if (npage == 0)
		{
			npage = 1;
		}
		return npage;
	}
};

//管理多个连续页大块内存跨度结构
struct Span
{
	PAGE_ID _pageId = 0;   //大块内存起始页的页号
	size_t _n = 0;         //页的数量

	//采用双链表结构，便于增删
	Span* _next = nullptr;
	Span* _prev = nullptr;

	size_t _useCount = 0; //切好小块内存，被分配给thread cache的计数
	void* _freeList = nullptr;  //切好的小块内存的自由链表

	bool _isUse = false; //是否在被使用
};

//带头双向循环链表
class SpanList
{
public:
	SpanList()
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}

	Span* Begin()
	{
		return _head->_next;
	}
	Span* End()
	{
		return _head;
	}
	
	//链表判空
	bool Empty()
	{
		return _head->_next == _head;
	}

	//头删
	Span* PopFront()
	{
		Span* front = _head->_next;
		Erase(front);
		return front;
	}

	//头插span
	void PushFront(Span* span)
	{
		Insert(Begin(), span);
	}

	//prev newSpan pos
	void Insert(Span* pos, Span* newSpan)
	{
		assert(pos);
		assert(newSpan);

		Span* prev = pos->_prev;
		prev->_next = newSpan;
		newSpan->_prev = prev;
		newSpan->_next = pos;
		pos->_prev = newSpan;
	}

	void Erase(Span* pos)
	{
		assert(pos);
		assert(pos != _head);

		Span* prev = pos->_prev;
		Span* next = pos->_next;

		prev->_next = next;
		next->_prev = prev;
	}
private:
	Span* _head;
public:
	std::mutex _mtx; //桶锁
};