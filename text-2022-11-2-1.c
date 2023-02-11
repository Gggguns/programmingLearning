#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//µÝ¹éì³²¨ÄÇÆõÊý
int Cal_Fib(num)
{
	if (num == 0)
	{
		return 0;
	}

	if (num == 1 || num == 2)
		return 1;
	else
		return Cal_Fib(num - 1) + Cal_Fib(num - 2);
}
int main()
{
	int num,fib,num1=1,num2=1;
	scanf("%d", &num);
	printf("%d\n", Cal_Fib(num));
	//·ÇµÝ¹éì³²¨ÄÇÆõÊý
	if (num == 1 || num == 2)
	{
		printf("%d\n", 1);
	}
	else if (num == 0)
		printf("%d",0);
	else
	{
		num = num - 2;
		while (num--)
		{
			fib = num1 + num2;
			num1 = num2;
			num2 = fib;
		}
		printf("%d\n", fib);
	}
	return 0;
}