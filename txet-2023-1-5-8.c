#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stu
{
	char name[10];
	int age;
};
int cmp(const void* e1,const void* e2)
{
	return *(int*)e1 - *(int*)e2; 
}
int cmp1(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}
int cmp2(const void* e1, const void* e2)
{
	return strcmp((struct stu*)e1, (struct stu*)e2);
}
void Swap(char* p1, char* p2, size_t width)
{
	int i;
	char c;
	for (i = 0;i < width;i++)
	{
		c = *(p1+i);
		*(p1+i) = *(p2 + i);
		*(p2 + i) = c;
		/*p1++;
		p2++;*/
	}
}
void bubble_sort(void* base, size_t num, size_t width, int(*cmp)(const void*, const void*))
{
	int i, j;
	for (i = 0;i < num - 1;i++)
	{
		for (j = 0;j < num - 1 - i;j++)
		{
			if (cmp((char*)base+j * width, (char*)base+(j + 1) * width) > 0)
				Swap((char*)base+j * width, (char*)base+(j + 1) * width,width);
		}
	}
}

int main()
{
	//int ≤‚ ‘
	int arr[10] = { 5,6,2,9,4,3,7,1,0,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
	for (int i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//char ≤‚ ‘
	char arr1[10] = { 'a','f','d','r','w','v','n','l','b','q' };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	bubble_sort(arr1,sz1, sizeof(arr1[0]), cmp1);
	for (int i = 0;i < sz1; i++)
	{
		printf("%c ", arr1[i]);
	}
	printf("\n");
	//Ω·ππÃÂ≤‚ ‘
	struct stu arr2[3] = { {"zhann",10},{"qncnq",20},{"zhcunc",90} };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	bubble_sort(arr2, sz2, sizeof(arr2[0]), cmp2);
	for (int i = 0;i < sz2;i++)
	{
		printf("%s\n", arr2[i].name);
	}

	return 0;
}