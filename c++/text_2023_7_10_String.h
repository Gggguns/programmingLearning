#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

//模拟string使用的命名空间
namespace zjh
{
	class string
	{
		friend istream& operator>>(istream& cin, string& s);
		friend ostream& operator<<(ostream& cout, const string& s);
	public:
		//初始化
		string(const char*str)
		{
			_size = strlen(str);
			_capacity = _size+1;
			_str = new char[_capacity];
			strcpy(_str, str);
		}
		//开空间
		void reserve(size_t size)
		{
			assert(size >= 0);
			if(size>_capacity)
			{
				char* ret = new char[size + 1];
				_capacity = size + 1;
				strcpy(ret, _str);
				delete(_str);
				_str = ret;
			}
			
		}
		//拷贝函数
		string(const string& s) 
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[s._capacity];
			strcpy(_str, s._str);
		}
		//析构释放空间
		~string()
		{
			_size = 0;
			_capacity = 0;
			delete(_str);
		}
		//
		//迭代器
		typedef char* iterator;
		//起始位置
		iterator begin()
		{
			return _str;
		}
		const iterator begin()const
		{
			return _str;
		}
		//末尾位置
		iterator end()
		{
			return _str + _size;
		}
		const iterator end()const
		{
			return _str + _size;
		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
		const static size_t npos;
	};
	//const size_t string::npos = -1;
}