#define _CRT_SECURE_NO_WARNINGS
#include"Map.h"

void TestMap1()
{
	zjh::Map<int, int> m;
	m.Insert(make_pair(1, 1));
	m.Insert(make_pair(2, 2));
	m.Insert(make_pair(3, 3));
	m.Insert(make_pair(4, 4));
	m.Insert(make_pair(5, 5));
	m.Insert(make_pair(6, 6));
	m.Insert(make_pair(8, 8));
	m.Insert(make_pair(9, 9));
	m.Insert(make_pair(10, 10));
	for (auto e : m)
	{
		cout << e.first<<':'<<e.second << endl;
	}
}
int main()
{
	TestMap1();
	return 0;
}