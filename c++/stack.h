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
		void push(T& x)
		{
			c.push_back(x);
		}
		void pop
	private:
		Container c;
	};
}
