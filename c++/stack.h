#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<deque>
using namespace std;
namespace zjh
{
	template<class T,class Container=deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			c.push_back(x);
		}
		void pop()
		{
			c.pop_back();
		}
		const T& top()
		{
			return c.back();
		}
		size_t size()
		{
			return c.size();
		}
		bool empty()
		{
			return c.empty();
		}
	private:
		Container c;
	};
}
