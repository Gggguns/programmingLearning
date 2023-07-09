#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//模拟string使用的命名空间
namespace zjh
{
	class string
	{
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}