#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;
	int Max = num1, Min = num2;
	if (Min > Max)
	{
		Max ^= Min;
		Min ^= Max;
		Max ^= Min;
	}
	int r = 0;
	while (Min)
	{
		r = Max % Min;
		if (r == 0)
		{
			break;
		}
		Max = Min;
		Min = r;
	}
	cout << (num1 * num2 / Min);
	return 0;
}