#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Juage(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d是闰年\n", year);
	else
		printf("%d不是闰年\n", year);
}
int main()
{
	int year;
	scanf("%d", &year);
	Juage(year);
	return 0;
}