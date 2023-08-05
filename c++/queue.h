#pragma once
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<stack>
using namespace std;
namespace zjh
{
	template<class T,class Container=deque<T>>
	class Queue
	{
	public:
		void push(const T& value)
		{
			C.push_back(value);
		}
		void pop()
		{
			C.pop_front();
		}
		const T& front()
		{
			return C.front();
		}
		const T& back()
		{
			return C.back();
		}
		size_t size()
		{
			return C.size();
		}
		bool empty()
		{
			return C.empty();
		}
	private:
		Container C;
	};
}