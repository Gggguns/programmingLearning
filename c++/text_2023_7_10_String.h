#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

//模拟string使用的命名空间
namespace zjh
{
	class string
	{
	public:
		string(const char*str) 
		{
			_size = strlen(str);
			_capacity = _size;
			_str = reserve(_size);
			strcpy(_str, str);
		}
		char* reserve(size_t size) 
		{
			assert(size >= 0);
			char* ret = new char[size + 1];
			return ret;
		}
		string(const string& str) 
		{
			_size = str._size;
			_capacity = str._capacity;
			_str = new char[str._capacity];
			strcpy(_str, str._str);
		}
		~string()
		{
			_size = 0;
			_capacity = 0;
			delete(_str);
		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	};
}