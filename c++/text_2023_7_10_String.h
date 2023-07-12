#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//模拟string使用的命名空间
namespace zjh
{
	class string
	{
	public:
		string(std::size_t size = 0, std::size_t capacity = 4)
			:_size(size)
			,_capacity(capacity)
		{
			char
		}
	private:
		std::size_t _size;
		std::size_t _capacity;
		char* _str;
	};
}