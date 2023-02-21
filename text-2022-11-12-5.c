#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num = 0, sum1= 0, arr1[20]={0}, arr2[20]={0}, i = 0, j = 0, sum2 = 0;
	scanf("%d", &num);
	sum1= sizeof(num) * 8;
	sum2 = sum1;
	while (sum1)
	{
		if(sum1%2==0)
			if(num<0)
			{
				arr1[i] = 1; 
				i++;
			}
			else
			{
				arr1[i] = 0;
				i++;
			}
		else
		{ 
			if (num < 0) 
			{
				arr2[j] = 1;
				j++;
			}
			else
			{
				arr2[j] = 0;
				j++;
			}
		}
		sum1--;
		num <<= 1;
	}
	printf("偶数位:\n");
	for (i = 0;i < sum2 / 2;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n奇数位;\n");
	for (i = 0;i < sum2 / 2;i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}