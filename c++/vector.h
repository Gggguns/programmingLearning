#pragma once
#include<iostream>
namespace zjy
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}
		vector(const vector<T>& T = T())
		{
			_start = T._start;
			_finish = T._finish;
			_endofstorage = T._endofstorage;
		}

		size_t size()const
		{
			assert(_finish&&_start)
			return _finish - _star;
		}
		typedef T* iterator;
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	

}
