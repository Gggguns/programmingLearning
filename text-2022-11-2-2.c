#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
void reverse_string(char* arr)
	{
		assert(arr);
		int len = strlen(arr);
		char tmp;
		tmp = *arr;
		*arr = arr[len - 1];
		arr[len - 1] = '\0';
		if(2<len)
		reverse_string(arr + 1);
		arr[len - 1] = tmp;
	}
	int main()
	{
		char arr[] = "abcdefghijklmnov";
		reverse_string(arr);
		printf("%s", arr);
		return 0;
	}