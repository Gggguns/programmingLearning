#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	int left, right,judge,check;
	scanf("%d", &check);
	left = 0;
	right = sizeof(arr) / sizeof(arr[0]);
	for (;;)
	{
		if (left <= right)
		{
		judge = (left + right) / 2;
			if (check > arr[judge])
				left = judge+1;
			else if (check < arr[judge])
				right = judge-1;
			else if (check == arr[judge])
			{
				printf("%d", judge);
				break;
			}
		}
		else
		{
			printf("ÕÒ²»µ½\n");
			break;
		}
	}
	return 0;
}