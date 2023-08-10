#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* cp = NULL;
	if (!*s2)
		return s1;
	while (*s1)
	{
		cp = s1;
		while (*s2 == *cp && *s2 && *cp)
		{
			s2++;
			cp++;
		}		
		if (!*s2)
			return s1;
		s1++;
		s2 = str2;
	}
	return NULL;
}
int main()
{
	char arr1[] = "dk";
	char arr2[] = "dkc";
	char*p=my_strstr(arr1,arr2);
	if (p == NULL)
		printf("нч");
	else
		printf("%s", p);
	return 0;
}