#pragma once
#include "Common.h"
//操作系统有Windows和Linux两种，需要条件编译
#ifdef _WIN32
	#include<windows.h>
#else
	//Linux环境
#endif


//定长内存池
 
////非类型的模板参数
//template<size_t N>//这里的N表示内存池一次申请的空间大小
//class ObjectPool {
//};

////直接去堆上，按页申请空间
//inline static void* SystemAlloc(size_t kpage) 
//{
//#ifdef _WIN32
//	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);//kpage << 13与kpage*8*1024等价
//#else
//	//Linux下 brk mmap等
//#endif
//
//	if (ptr == nullptr)
//	{
//		throw std::bad_alloc();
//	}
//}
template<class T>
class ObjectPool 
{
public:
	T* New() 
	{
		T* obj;
		//优先把还回来的内存块对象，再重复利用
		if (_freeList)
		{
			//头删
			void* next = *((void**)_freeList);
			obj = (T*)_freeList;
			_freeList = next;
		}
		else
		{
			//剩余内存不够一个对象大小时，则重新开辟大块内存
			if (_remainBytes < sizeof(T))
			{
				_remainBytes = 128 * 1024;
				//_memory = (char*)malloc(_remainBytes);
				_memory = (char*)SystemAlloc(_remainBytes >> 13);//把页数传过去
				
				if (_memory == nullptr)
				{
					throw std::bad_alloc();//抛异常
				}
			}
			obj = (T*)_memory;
			size_t objSize = sizeof(T) > sizeof(void*) ? sizeof(T) : sizeof(void*);
			_memory += objSize;
			_remainBytes -= objSize;
		}
		//定位new，显示调用T的构造函数初始化
		new(obj)T;

		return obj;
	}
	void Delete(T* obj) 
	{
		//显示调用析构函数清理对象
		obj->~T();
		//头插
		//这里为什么我们要使用void**呢？
		//这是因为32位的系统指针大小是4字节，64位的是8字节。可以是其他类型的双指针
		*(void**)obj = _freeList;
		_freeList = (void*)obj;
	}
private:
	char* _memory = nullptr;// 只想大块内存的指针
	size_t _remainBytes = 0;// 大块内存切分过程剩余的字节数
	void* _freeList = nullptr;// 回收空间过程中的自由链表的头节点
};
struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

void TestObjectPool()
{
	// 申请释放的轮次
	const size_t Rounds = 5;

	// 每轮申请释放多少次
	const size_t N = 100000;

	std::vector<TreeNode*> v1;
	v1.reserve(N);

	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; ++i)
		{
			delete v1[i];
		}
		v1.clear();
	}

	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	ObjectPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.New());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.Delete(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	std::cout << "new cost time:" << end1 - begin1 << std::endl;
	std::cout << "object pool cost time:" << end2 - begin2 << std::endl;
}