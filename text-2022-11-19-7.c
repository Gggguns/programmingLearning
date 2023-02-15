#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", *(arr + i));
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 }, sz, i;
	sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	return 0;
}