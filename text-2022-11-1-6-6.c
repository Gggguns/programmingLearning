#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i,Judge,r,count=0;
	for (i = 1;i < 101;i++)
	{
		Judge = i;
		for (r = 1;r != 0;)
		{
			r = Judge % 10;
			Judge = Judge / 10;
			if (r == 9)
			{
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}