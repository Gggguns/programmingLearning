#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void my_strcpy(char* des, const char* rec)
{
	while (*des++ = *rec++)
	{
		;
	}
}
int main()
{
	char arr1[20] = "hello";
	char arr2[] = "hello bite";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}