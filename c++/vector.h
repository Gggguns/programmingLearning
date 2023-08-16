#pragma once
#include<iostream>
#include<assert.h>
#include<vector>
#include"reverse_iterator.h"
using namespace std;
namespace zjh
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(size_t n, const T& val = T())
		{
			_start = new T[n];
			size_t i = 0;
			for (i = 0;i < n;i++)
			{
				_start[i] = val;
			}
			_finish = _start + n;
			_endofstorage=_finish;
		}
		vector(int n, const T& val = T())
		{
			/*_start = new T[n];
			size_t i = 0;
			for (i = 0;i < n;i++)
			{
				_start[i] = val;
			}
			_finish = _start + n;
			_endofstorage = _finish;*/
			resize(n,val);
		}
		//øΩ±¥
		vector(const vector<T>& v)
		{
			size_t len = T.size();
			if(capacity()<len)
				reserve(len);
			int i = 0;
			for (i = 0;i < len;i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + len;
		}
		template<class InputIterator>

		vector(InputIterator first, InputIterator last)
		{
			reserve(last - first);
			int i = 0;
			while (first != last)
			{
				_start[i] = *first;
				i++;
				first++;
			}
			_finish = _start + i;
		}
		vector<T> operator=(const vector<T>& v)
		{
			size_t len = v.size();
			if (capacity() < len)
				reserve(len);
			int i = 0;
			for (i = 0;i < len;i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + len;
			return *this;
		}
		
		~vector()
		{
			delete[]_start;
			_start = nullptr;
			_finish = nullptr;
			_endofstorage = nullptr;
		}
		//µ¸¥˙∆˜
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		const_iterator cbegin()const
		{
			return _start;
		}
		const_iterator cend()const
		{
			return _finish;
		}
		//¿©»›
		void reserve(size_t n)
		{
			if (capacity() < n)
			{
				iterator tmp = new T[n];
				int i = 0;
				while (i<size())
				{
					tmp[i] = _start[i];
					i++;
				}
				size_t oldsize = size();
				delete[] _start;
				_start = tmp;
				_finish = tmp + oldsize;
				_endofstorage = tmp + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (capacity() < n)
			{
				iterator tmp = new T[n];
				int i = 0;
				for (i = 0;i < size();i++)
				{
					tmp[i] = _start[i];
				}
				
				delete[] _start;
				_start = tmp;
				_finish = _start + i;
				_endofstorage = _start + n;
				while (_finish != _endofstorage)
				{
					*_finish = value;
					_finish++;
				}
			}
			else
			{
				_finish = _start + n;
			}
			
		}
		//vectorµƒ¥Û–°
		size_t size()const
		{
			return _finish - _start;
		}
		//vectorµƒ»›¡ø
		size_t capacity()const
		{	
			return _endofstorage - _start;
		}
		//∑Ω¿®∫≈‘ÀÀ„∑˚÷ÿ‘ÿ
		T& operator[](size_t pos)
		{
			assert(pos < capacity());
			return _start[pos];
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < capacity());
			return _start[pos];
		}
		//Œ≤≤Â
		void push_back(const T& x)
		{
			if (capacity() == size())
			{
				int newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}
		//Œ≤…æ
		void pop_back()
		{
			_finish--;
		}
		//Ωªªª
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		//posŒª÷√≤Â»Î
		iterator insert(iterator pos, const T& x)
		{
			size_t n = pos - begin();
			if (capacity() == size())
			{
				int newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			iterator end1= end();
			pos = begin() + n;
			while (end1 != pos)
			{
				*end1 = *(end1-1);
				end1--;
			}
			_finish++;
			*pos = x;
			return pos;
		}
		//posŒª÷√…æ≥˝
		iterator erase(iterator pos)
		{
			iterator end = pos;
			_finish--;
			while (end - 1 != _finish)
			{
				*end = *(end + 1);
				end++;
			}
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	

}
