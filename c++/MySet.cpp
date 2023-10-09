#define _CRT_SECURE_NO_WARNINGS
#include"Set.h"

void testSet1()
{
	zjh::Set<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(3);
	s.Insert(4);
	s.Insert(5);
	s.Insert(6);
	s.Insert(7);
	s.Insert(7);
	s.Insert(8);
	zjh::Set<int>::Iterator it = s.begin();
	//while (it != s.end())
	//{
	//	//(*it) += 1;
	//	++it;
	//}
	for (auto e : s)
	{
		cout << e << ' ';
	}
	cout << endl;
	cout << *(s.Find(8)) << endl;
	//cout << '9' << endl;
	set<int> s1; 
}
void testSet2()
{
	zjh::Set<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(3);
	s.Insert(4);
	s.Insert(5);
	s.Insert(6);
	s.Insert(7);
	s.Insert(8);
	/*cout<<s[9]<<endl;*/
	for (auto e : s)
	{
		cout << e << ' ';
	}
}
int main()
{
	testSet2();
	return 0;
}