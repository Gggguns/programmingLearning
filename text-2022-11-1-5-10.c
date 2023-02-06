#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int year = 1000;
	while (year)
	{
		if (2000 < year)
			break;
		if (year%400==0||(year%4==0&&year%100!=0))
			printf("%d ", year);
		year++;
	}
	return 0;
}