#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp1(const void *e1,const void *e2)
{
	return  *(int*)e1 - *(int*)e2;
}//整型的比较函数
int cmp2(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2; 
}//字符型的比较
struct stu
{
	char name[20];
	int age;
};
int cmp3(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
int cmp4(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int main()
{
	//利用qsort进行整型的排序
	int arr1[10] = { 6,4,9,2,7,5,3,8,1,0 },i,sz1;
	sz1 = sizeof(arr1)/sizeof(arr1[0]);
	qsort(arr1, sz1, sizeof(arr1[0]), cmp1);
	for (i = 0;i < sz1;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	//利用qsort进行字符型的比较
	char arr2[10] = { 'a','b','c','f','d','e','g','h','i','j' };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	qsort(arr2, sz2, sizeof(arr2[0]), cmp2);
	for (i = 0;i < sz2;i++)
	{
		printf("%c ", arr2[i]);
	}
	printf("\n");
	//利用qsort进行结构体的比较
	struct stu arr3[4] = { {"zhang",10},{"zhou",50},{"li",20},{"zhazha",99}};
	int sz3 = sizeof(arr3) / sizeof(arr3[0]);
	qsort(arr3, sz3, sizeof(arr3[0]), cmp3);
	printf("结构体字符串的比较\n");
	for (i = 0;i < sz3;i++)
	{
		printf("%s\n", arr3[i].name);
	}
	qsort(arr3, sz3, sizeof(arr3[0]), cmp4);
	for (i = 0;i < sz3;i++)
	{
		printf("%s %d\n", arr3[i].name,arr3[i].age);
	}
	return 0;
}