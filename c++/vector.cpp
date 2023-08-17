#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"
void textvector1()
{
	zjh::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9); 
	v.push_back(10);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
	v.insert(v.begin()+3, 666);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
	v.erase(v.begin() + 3);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}
void textvector2()
{
	zjh::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	zjh::vector<int>::iterator it = v.begin();
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
	while(it != v.end())
	{
		it = v.erase(it);
	}
	v.push_back(1);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}
void textvector3()
{
	zjh::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	zjh::vector<int> v2(v1.begin(),v1.end());
	for (auto e : v2)
	{
		cout << e << ' ';
	}
	cout << endl;
	cout << v1[9] << endl;
}
void textvector4()
{
	zjh::vector<int> v(10, 1);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}
void textvector5()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
	v.resize(20);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
	//vector<int> v1;

}
int main()
{	
	textvector5();
	return 0;
}
