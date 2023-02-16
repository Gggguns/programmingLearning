#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int J_digit(int num)
{
	int i = 0;
	if (num < 10)
		return 1;
	else
	{
		while (num)
		{
			i++;
			num = num / 10;
		}
		return i;
	}
}
int Nar_num(int num,int dig)
{
	int sum = 0,r=0,j=num;
	if (j == 0)
		return 1;
	else
	{
		while (j)
		{
			r = j % 10;
			sum = sum + pow(r, dig);
			j=j / 10;
		}
		if (sum == num)
			return 1;
		else
			return 0;
	}
}
int main()
{
	int num = 0,dig=0,ret=0;
	while(num<100001)
	{ 
		dig=J_digit(num);
		ret=Nar_num(num,dig);
		if (ret == 1)
			printf("%d ", num);
		num++;
	}
	return 0;
}