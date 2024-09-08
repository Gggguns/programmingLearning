#define _CRT_SECURE_NO_WARNINGS
#include "ObjectPool.hpp"
#include "ConcurrentAlloc.h"

void Alloc1()
{
	for (size_t i = 0;i < 5;i++)
	{
		void* ptr = ConcurrentAlloc(7);
	}
}

void Alloc2()
{
	for (size_t i = 0;i < 5;i++)
	{
		void* ptr = ConcurrentAlloc(7);
	}
}
void TLSTest()
{
	//创建线程，分配任务
	std::thread t1(Alloc1);
	std::thread t2(Alloc2);

	//回收线程
	t1.join();
	t2.join();
}

void TestConcurrentAlloc1()
{
	void* p1 = ConcurrentAlloc(6);
	void* p2 = ConcurrentAlloc(8);
	void* p3 = ConcurrentAlloc(1);
	void* p4 = ConcurrentAlloc(7);
	void* p5 = ConcurrentAlloc(8);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;
	std::cout << p5 << std::endl;
}
void TestConcurrentAlloc2()
{
	
	for (size_t i = 0;i < 1024;i++)
	{
		void* p1 = ConcurrentAlloc(6);
		std::cout << p1 << std::endl;
	}

	void* p2 = ConcurrentAlloc(8);
	std::cout << p2 << std::endl;
}

void TestAddressShift()
{
	PAGE_ID id1 = 2000;
	PAGE_ID id2 = 2001;

	char* p1 = (char*)(id1 << PAGE_SHIFT);
	char* p2 = (char*)(id2 << PAGE_SHIFT);

	while (p1 < p2)
	{
		std::cout << (void*)p1 << ":" << ((PAGE_ID)p1 >> PAGE_SHIFT) << std::endl;
		p1 += 8;
	}
}

int main()
{
	//TestObjectPool();
	//TLSTest();
	//TestConcurrentAlloc2();
	TestAddressShift();
	return 0;
}