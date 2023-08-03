#define _CRT_SECURE_NO_WARNINGS
#include"list.h"


void listtext1()
{
	zjh::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);
	for (auto i : l)
	{
		cout << i << ' ';
	}
	cout << endl;
	zjh::list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		it = l.erase(it);
	}
	//cout << l.back() << endl;
	//std::list<int> L;
	/*cout<<L.front()<<endl;
	cout<<L.back()<<endl;*/
}
void listtext2()
{
	zjh::list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.push_front(5);
	l.push_front(6);
	l.push_front(7);
	l.push_front(8);
	l.push_front(9);
	l.push_front(10);
	l.pop_front();
	l.pop_back();
	for (auto i : l)
	{
		cout << i << ' ';
	}
	cout << endl;
	cout << l.size() << endl;
}
void listtext3()
{
	zjh::list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.push_front(5);
	l.push_front(6);
	l.push_front(7);
	l.push_front(8);
	l.push_front(9);
	l.push_front(10);
	zjh::list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << (*it) << ' ';
		it++;
	}
	cout << endl;
	l.clear();
	cout << l.size() << endl;
}
void listtext4()
{
	zjh::list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.push_front(5);
	l.push_front(6);
	l.push_front(7);
	l.push_front(8);
	l.push_front(9);
	for (auto e : l)
	{
		cout << e << ' ';
	}
	cout << endl;
	zjh::list<int> i (l.begin(),l.end());
	l.push_front(10);
	l.push_front(11);
	l.push_front(12);
	l.push_front(13);
	i.insert(++i.begin(),20);
	for (auto e : l)
	{
		cout << e << ' ';
	}
	cout << endl;
	for (auto e : i)
	{
		cout << e << ' ';
	}
	cout << endl;
	l = i;
	for (auto e : l)
	{
		cout << e << ' ';
	}
	cout << endl;
}
void listtext5()
{
	zjh::list<int> l(10,1);
	for (auto e : l)
	{
		cout << e << ' ';
	}
	cout << endl;
}
int main()
{
	listtext5();
	return 0;
}

