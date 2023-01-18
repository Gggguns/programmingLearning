#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* str1, const char* str2)
{
	const char *s1 = NULL;
	const char *s2 = NULL;
	const char* cp = str1;
	assert(str1 && str2);
	if (!*str2)
		return str1;
	while(*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return cp;
		cp++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "cussssesskanudkjnckjsn kdskcmcslkcscsdkcskcscscdscds";
	char arr2[] = "skc";
	printf("%s\n", my_strstr(arr1, arr2));
	return 0;
}