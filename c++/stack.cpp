#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
void TextStack1()
{
	zjh::stack<int, vector<int>> s;
	cout << s.empty() << endl;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	cout << s.size() << endl;
	cout << s.top() << endl;
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
}
int main()
{
	TextStack1();
	return 0;
}