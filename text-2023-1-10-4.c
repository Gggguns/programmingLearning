#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* des, const void *sce, size_t num)
{
	void* ret = des;
	while (num--)
	{
		*(char*)des = *(char*)sce;
		des = (char*)des + 1; 
		sce = (char*)sce + 1;
	}
	return ret;
}
void text1()
{
	int i;
	int arr1[20] = { 1,5,6,3,5,8,8,9,9,8,4,5,5,2,22,2,5,2,3,5 };
	int arr2[5] = { 1,2,3,4,5 };
	my_memcpy(arr1+2, arr2,20);
	for (i = 0;i < 20;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
}
void text2()
{
	char arr1[] = "sjndckjnc;anvjav;jfdvjnfjnvjdjfdnv";
	char arr2[] = "abcdef";
	my_memcpy(arr1+3, arr2, 6);
	printf("%s\n", arr1);
}
int main()
{
	text1();
	text2();
	return 0;
}