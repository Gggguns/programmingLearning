#pragma once
#include "Common.h"
#include "ThreadCache.h"
#include "PageCache.h"


//用static修饰函数，否则多个.cpp文件包含同一个.h时，会导致链接错误
static void* ConcurrentAlloc(size_t size)
{
	if (size > MAX_BYTES)
	{
		//对齐
		size_t alignSize = SizeClass::RoundUp(size);
		//确定页数
		size_t kpage = alignSize >> PAGE_SHIFT;

		//申请k页
		PageCache::GetInstance()->_pageMtx.lock();
		Span* span = PageCache::GetInstance()->NewSpan(kpage);
		span->_objSize = size;
		PageCache::GetInstance()->_pageMtx.unlock();

		void* ptr = (void*)(span->_pageId << PAGE_SHIFT);
		return ptr;
	}
	else
	{
		//通过TLS 每个线程无锁的获取自己专属的ThreadCache对象
		if (pTLSthreadCache == nullptr)
		{
			static ObjectPool<ThreadCache> tcPool;
			//pTLSthreadCache = new ThreadCache;
			tcPool._oPoolMtx.lock();
			pTLSthreadCache = tcPool.New();
			tcPool._oPoolMtx.unlock();
		}
		//debug
		//std::cout << std::this_thread::get_id() << ": " << pTLSthreadCache << std::endl;

		return pTLSthreadCache->Allocate(size);//将申请到的空间返回
	}
}
static void ConcurrentFree(void* ptr)
{
	//PageCache::GetInstance()->_pageMtx.lock();
	//找映射
	Span* span = PageCache::GetInstance()->MapObjectToSpan(ptr);
	//PageCache::GetInstance()->_pageMtx.unlock();
	//获取对象大小
	size_t size = span->_objSize;
	if (size > MAX_BYTES) 
	{
		PageCache::GetInstance()->_pageMtx.lock();
		PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		PageCache::GetInstance()->_pageMtx.unlock();

	}
	else
	{
		assert(pTLSthreadCache);
		//回收空间
		pTLSthreadCache->DeAllocate(ptr, size);
	}
}