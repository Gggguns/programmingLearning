#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* des, const char* res)
{
	assert(des && res);
	char* ret = des;
	while (*des++ = *res++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[55] = "hello ";
	char arr2[] = "my name is doudou";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}