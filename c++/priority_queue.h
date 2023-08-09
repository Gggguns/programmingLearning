#pragma once
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
namespace zjh
{
	template<class T>
	struct Less
	{
		bool compare(const T& x, const T& y)
		{
			return x > y;
		}
	};
	template<class T>
	struct Greater
	{
		bool compare(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T,class Container=vector<T>,class Compare=Less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if ((child + 1) < _con.size() && com.compare(_con[child] , _con[child + 1]))
				{
					child++;
				}
				if (com.compare(_con[parent] , _con[child]))
				{
					std::swap(_con[parent] , _con[child]);
				}
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		void AdjustDown(int parent)
		{
			Compare com;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if ((child + 1) < _con.size() && com.compare(_con[child] , _con[child + 1]))
				{
					child++;
				}
				if (com.compare(_con[parent] , _con[child]))
				{
					std::swap(_con[parent], _con[child]);
				}
				parent = child;
				child = parent * 2 + 1;
			}
		}
		void push(const T& value)
		{
			_con.push_back(value);
			AdjustUp(_con.size()-1);
		}
		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.size() == 0;
		}
		const T& top()const
		{
			return _con[0];
		}
	private:
		Container _con;
	};
}
