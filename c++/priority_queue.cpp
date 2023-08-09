#define _CRT_SECURE_NO_WARNINGS
#include"priority_queue.h"
#define N 10
void textpriority_queue1()
{
	zjh::priority_queue<int, vector<int>,zjh::Greater<int>> Q;
	srand(time(NULL));
	int i = 0;
	for (i = 0;i < N;i++)
	{
		int ran = rand() / 100;
		Q.push(ran);
	}
	cout << Q.size() << endl;
	cout << Q.empty() << endl;
	for (i = 0;i < N;i++)
	{
		cout << Q.top() << ' ';
		Q.pop();
	}
}
int main()
{
	textpriority_queue1();
	//cout << 9 % 2 << endl;
	return 0;
}