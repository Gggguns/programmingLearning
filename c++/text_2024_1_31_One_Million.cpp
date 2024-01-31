#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int i = 0;
	vector<int> Fac(1, 1);
	for (i = 1;i < n + 1;i++)
	{
		int Mul = i;
		int j = 0;//第j为数据
		int Carry = 0;//进位
		int res = 0;
		int Current = 0;
		for (j = 0;j < Fac.size();j++)
		{
			//两数相乘的结果res
			res = Fac[j] * Mul;
			Current = res % 10;
			Fac[j] = Carry + Current;
			Carry = (res / 10) + (Fac[j] / 10);
			Fac[j] %= 10;
		}

		while(j < Fac.size())
		{
			Fac[j] += Carry;
			Carry = Fac[j] / 10;
			Fac[j] %= 10;
		}
		while(Carry)
		{
			Fac.push_back(Carry%10);
			Carry /= 10;
		}
	}
	reverse(Fac.begin(), Fac.end());
	for (auto e : Fac)
	{
		cout << e;
	}
	cout << endl;
	return 0;
}
