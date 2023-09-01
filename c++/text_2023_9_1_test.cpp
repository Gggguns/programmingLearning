#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	float Sum = 0;
	float SumCredit = 0;
	cout << "请输入要计算的科目总数：" << endl;
	int count = 0;
	cin >> count;
	while (count--)
	{
		float general = 0;
		float credit = 0;
		cout << "请依次输入每科的总评和学分，以空格作为间隔符:" << endl;
		cin >> general >> credit;
		SumCredit = SumCredit + credit;
		Sum = Sum + general * credit;
	}
	cout << Sum / SumCredit << endl;

	return 0;
}