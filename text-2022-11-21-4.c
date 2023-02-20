#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Count_one(int num)
{
	int t = 0,x=32,count=0;
	if (num == 0)
		return 0;
	else if (num < 0)
	{
		t = num;
		while (x--) 
		{
			if (t < 0)
				count++;
			t <<= 1;
		}
		return count;
	}
	else
	{
		t = num;
		while (x--)
		{
			if (t < 0)
				count++;
			t <<= 1;
		}
		return count;
	}
}
int main()
{
	int num = 0,ret=0;
	scanf("%d", &num);
	ret=Count_one(num);
	printf("%d", ret);
	return 0;
}