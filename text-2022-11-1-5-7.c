#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int count = 100;
	while (count)
	{
		if (count % 3 == 0)
			printf("%d ", count);
		count--;
	}
	return 0;
}