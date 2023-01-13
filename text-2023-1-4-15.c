#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],c[100];
	int k;
	int le_ro(char a[], int len, char c[]);
	gets(a);
	gets(c);
	k=le_ro(a, strlen(a),c);
	if (k==1)
		printf("×Ö·û´®1ÎªÐý×ªºóµÄ×Ö·û´®2");
	else
		printf("×Ö·û´®1²»ÎªÐý×ªºóµÄ×Ö·û´®2");
	return 0;
}
int le_ro(char a[], int len, char c[])
{
	char b;
	int i, j;
	for (i = 0;i < len;i++)
	{
		b = a[0];
		for (j = 0;j < len - 1;j++)
		{
			a[j] = a[j + 1];
		}
		a[len - 1] = b;
		if ((strcmp(a, c)) == 0)
			return 1;
	}
	return 0;
}