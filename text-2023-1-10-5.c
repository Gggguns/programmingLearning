#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memmove(void* des, const void* sce, size_t num)
{
	assert(des && sce);
	void *ret = des;
	if (des <= sce)
	{
		while (num--)
		{
			*(char*)des = *(char*)sce;
			des = (char *)des + 1;
			sce = (char *)sce + 1;
		}
	}
	else
	{
		while (num--)
		{
			*((char*)des + num) = *((char*)sce + num);
		}

	}
	return ret;
}
void text1()
{
	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	my_memmove(arr1, arr1 + 4, 20);
	for (int i = 0;i < 20;i++)
	{
		printf("%d ", arr1[i]);
	}
}
void text2()
{
	char arr1[] = "abcdefghijklmnop";
	my_memmove(arr1 + 4, arr1, 5);
	printf("\n%s", arr1);
}
int main()
{
	text1();
	text2();
	return 0;
}