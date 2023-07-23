#pragma once
#include<iostream>
namespace zjy
{
	template<class T>
	class vector
	{
		typedef T* iterator;
	private:
		iterator star;
		iterator finsh;
		iterator endofshorch;
	};
}
