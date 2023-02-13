#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void init(int*p,int sz)
{
	int i=0;
	while (sz--)
	{
		p[i] = 0;
		i++;
	}
}
void print(int* p, int sz)
{
	int i = 0;
	while (sz--)
	{
		printf("%d ", p[i]);
		i++;
	}
	printf("\n");
}
void reverse(int* p, int sz)
{
	int i=0,tmp=0;
	for (i = 0;i < sz / 2;i++)
	{
		tmp = p[i];
		p[i] = p[sz - 1 - i];
		p[sz - 1 - i] = tmp;

	}
}
int main()
{
	int arr[11] = { 1,2,3,4,5,6,7,8,9,10 ,11 };
	int sz = 0;
	int i = 0,j=0;
	sz = sizeof(arr) / sizeof(arr[0]);
	init(arr, sz);
	printf("初始化:");
	print(arr, sz);
	for (i = 2,j=0;j < sz;i++,j++)
	{
		arr[j] = i;
	}
	printf("赋值后:");
	print(arr, sz);
	reverse(arr, sz);
	printf("逆置后:");
	print(arr, sz);

	return 0;
}