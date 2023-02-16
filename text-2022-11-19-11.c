#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int Sn = 0, a = 0, mid = 0;
	scanf("%d", &a);
	mid = a;
	for (int i = 0;i < 5;i++)
	{
		Sn = mid + Sn;
		printf("%d ", mid);
		mid = mid * 10 + a;
	}
	printf("%d", Sn);
	return 0;
}