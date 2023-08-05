#define _CRT_SECURE_NO_WARNINGS
#include"queue.h"
void TextQueue1()
{
	zjh::Queue<int,list<int>> Q;
	cout << Q.empty() << endl;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	Q.push(5);
	Q.push(6);
	Q.push(7);
	Q.push(8);
	Q.push(9);
	//¶ÓÎ²
	cout << Q.back() << endl;

	//¶ÓÍ·
	cout << Q.front() << endl;
	while (!Q.empty())
	{
		cout << Q.front() << ' ';
		Q.pop();
	}
	cout << endl;
}
void TextQueue2()
{
	zjh::Queue<char, list<char>> Q;
	Q.push('a');
	Q.push('b');
	Q.push('c');
	Q.push('d');
	Q.push('e');
	Q.push('f');
	Q.push('h');
	Q.push('g');
	cout << Q.front() << endl;
	cout << Q.back() << endl;
	while (!Q.empty())
	{
		cout << Q.front() << ' ';
		Q.pop();
	}
	cout << endl;
}
int main()
{
	TextQueue2();
	return 0;
}