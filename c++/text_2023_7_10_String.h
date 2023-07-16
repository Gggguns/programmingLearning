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
		void reserve(size_t n)
		{
			assert(n >= 0);
			if(n>=_capacity-1)
			{
				char* ret = new char[n + 1];
				_capacity = n + 1;
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
		//尾插一个字符
		void push_back(char c)
		{
			_size++;
			reserve(_size);
			_str[_size - 1] = c;
			_str[_size] = '\0';
		}
		//追加字符串
		void append(const char* str)
		{
			int len = strlen(str);
			_size += len;
			reserve(_size);
			strcpy(_str + _size - len, str);
		}
		//获取字符串
		const char* c_str()const
		{
			return _str;
		}
		//获取数据个数
		size_t size()const
		{
			return _size;
		}
		//获取容量数据
		size_t capacity()const
		{
			return _capacity;
		}
		//清除数据
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		//判空
		bool empty()const
		{
			return _size == 0;
		}
		//开空间+初始化
		void resize(size_t n, char c = '\0')
		{
			assert(n >= 0);
			if (n >= _capacity - 1)
			{
				char* ret = new char[n + 1];
				_capacity = n + 1;
				strcpy(ret, _str);
				delete(_str);
				_str = ret;
				memset(_str + _size , c, _capacity - _size);
			}
			_size = n;
			_str[n] = '\0';
		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
		const static size_t npos;
	};
	//const size_t string::npos = -1;
}