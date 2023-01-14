#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[5][5] = { {1,3,5,7,9},{2,4,6,8,10},{3,5,7,9,11},{4,6,8,10,12},{5,7,9,11,13} };
	int n,k=5,b=5,t,flat,i,j;
	scanf("%d", &n);
	if (n == a[0][k / 2])
		printf("存在%d", n);
	else if (n < a[0][k / 2])
	{
		t = k/2 + 1;
		i = 0;
	}
	else
	{
		i = k/2;
		t = k;
	}
	for (;i < t;i++)
	{
		for (j = 0;j < b;j++)
		{
			flat = 0;
			if(a[i][j]==n)
			{
				flat = 1;
				printf("存在%d", n);
				break;
			}

		}
		if (flat == 1)
			break;
	}
	if(flat==0)
		printf("不存在%d", n);
	return 0;
} 