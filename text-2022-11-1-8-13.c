#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Juage_P(int num)
{
	int i,flat=1;
	for (i = 2;i < num;i++)
	{
		if (num % i == 0)
		{
			flat = 0;
			break;
		}
	}
	if (1 == flat)
		return 1;
	return 0;
}
int main()
{
	int ret, i;
	for(i=100;i<201;i++)
	{
		ret = Juage_P(i);
		if (1 == ret)
			printf("%d ", i);
	}
	return 0;
}