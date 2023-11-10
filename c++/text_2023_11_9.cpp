#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//首先，我们先定义一个参数列表，我们通常交换两个类型相同的函数，所以，这里我们只需要一个模板参数
template<class T>
//其次，完成交换函数的实现
void Swap(T& left,T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}
//两数相加
template<class T2>
T2 Add(const T2& x, const T2& y)
{
	cout << "我走了函数模板\n";
	return x + y;
}

//专门处理int类型
int Add(int left,int right)
{
	cout << "我没走函数模板\n";
	return left+right;
}
void testSwap1()
{
	double a = 10.2;
	double b = 12.3;
	cout << "交换前：" << endl;
	cout << "a:" << a << ' ' << "b:" << b << endl;
	Swap(a, b);
	cout << "交换后:\n";
	cout << "a:" << a << ' ' << "b:" << b << endl;
}

void testSwap2()
{
	double a = 10.5;
	int b = 90;
	int c = 10;
	//Swap(a, b);
	//隐式类型转换，编译器会传过去的类型自动推导
	cout << Add(b, c) << endl;
	cout << Add(a, (double)b) << endl;//对变量b进行类型转换

	//显示类型转化
	//cout << Add(a, b) << endl;
	cout << Add<double>(a, b) << endl;
	
}

void testSwap3()
{
	int a = 10;
	int b = 20;
	cout << Add(a, b) << endl;
}

//先定义参数列表
template<class Type>
//定义类模板
struct Stack
{
public:
	bool InitStack()
	{
		_size = 0;
		_ptr = (Type*)malloc(sizeof(Type) * 4);
		if (_ptr!=NULL)
		{
			_capacity = 4;
		}
		else
		{
			_capacity = 0;
		}
		return true;
	}
	//入栈
	bool Push(Type val)
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity > 0 ? 2 * _capacity : 4;
			Type* ptr = (Type*)realloc(_ptr, sizeof(Type) * newcapacity);
			if (ptr==NULL)
			{
				return false;
			}
			_ptr = ptr;
			ptr = NULL;
			_capacity = newcapacity;
		}
		_ptr[_size++] = val;
		return true;
	}
	
	//出栈
	bool Pop()
	{
		//...
		if (_size)
		{
			_size--;
			return true;
		}
		return false;
	}

	//栈顶元素
	Type Top()
	{
		return _ptr[_size - 1];
	}

	//判空
	bool EmptyStack()
	{
		return _size == 0;
	}
private:
	Type* _ptr;
	int _size;
	int _capacity;
};

void testStack1()
{
	Stack<int> s;
	s.InitStack();
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	s.Push(6);
	s.Push(7);
	while (!s.EmptyStack())
	{
		cout << s.Top() << ' ';
		s.Pop();
	}
}
void testStack2()
{
	//Stack在这里与之前不同，不是类型，而是类模板，Stack<int> 这样才是类型
	Stack<double> s;
	s.InitStack();
	s.Push(1.8);
	s.Push(5.2);
	s.Push(3.3);
	s.Push(4.5);
	s.Push(4.5);
	s.Push(6.6);
	s.Push(7.3);
	while (!s.EmptyStack())
	{
		cout << s.Top() << ' ';
		s.Pop();
	}
}
int main()
{
	//testSwap3();
	testStack2();

	return 0;
}