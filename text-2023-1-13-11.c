#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
char* my_strncpy(char* des, const char* ses, size_t num)
{
	assert(des && ses);
	char* ret = des;
	while (*des++ = *ses++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[30]="cdj";
	char arr2[] = "dssvvdsvd";
	my_strncpy(arr1,arr2,strlen(arr2));
	printf("%s", arr1);
	return 0;
}