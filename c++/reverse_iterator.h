#pragma once
#include<iostream>
using namespace std;
namespace zjh
{
	template<class Iterator,class Ref,class Ptr>
	struct ReverseIterator
	{
		typedef ReverseIterator< Iterator, Ref, Ptr> self;
		Iterator _it;
		ReverseIterator(Iterator it)
			:_it(it)
		{}
		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}
		Iterator& operator++()
		{
			_it--;
			return _it;
		}
		Iterator operator++(int)
		{
			Iterator ret = _it;
			_it--;
			return ret;
		}
		Iterator& operator--()
		{
			_it++;
			return _it;
		}
		Iterator operator--(int)
		{
			Iterator ret = _it;
			_it++;
			return ret;
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		bool operator==(const self& s)
		{
			return _it == s._it;
		}
		bool operator!=(const self& s)
		{
			return _it != s._it;
		}
	
		
	};
}