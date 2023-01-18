#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* des,const char* res)
{
	char* ret = des;
	assert(des && res);
	while (*des)
	{
		des++;
	}
	while (*des++ = *res++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[50] = "hello ";
	char arr2[] = "pppp cnn";
	my_strcat(arr1, arr2);
	printf("%s", arr1);
	return 0;
}