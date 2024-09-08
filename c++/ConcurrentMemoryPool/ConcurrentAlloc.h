#pragma once
#include "Common.h"
#include "ThreadCache.h"

//用static修饰函数，否则多个.cpp文件包含同一个.h时，会导致链接错误
static void* ConcurrentAlloc(size_t size)
{
	//通过TLS 每个线程无锁的获取自己专属的ThreadCache对象
	if (pTLSthreadCache == nullptr)
	{
		pTLSthreadCache = new ThreadCache;
	}
	//debug
	std::cout << std::this_thread::get_id() << ": " << pTLSthreadCache << std::endl;
	
	return pTLSthreadCache->Allocate(size);//将申请到的空间返回
}
static void ConcurrentFree(void* ptr, size_t size)
{
	assert(pTLSthreadCache);
	//回收空间
	pTLSthreadCache->DeAllocate(ptr, size);
}