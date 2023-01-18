#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0; 
		str1++;
		str2++;
	}
    if (*str1 > *str2)
		return 1;
	else
		return -1;
}
int main()
{
	char arr1[] = "sdabibjai";
	char arr2[] = "sdcnbisjcs";
	int ret=my_strcmp(arr1, arr2);
	if (ret > 0)
		printf(">\n");
	else if (ret == 0)
		printf("=\n");
	else
		printf("<\n");
	return 0;
}
