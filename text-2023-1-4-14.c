#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int k=0;
	void le_ro(char a[], int k,int len);
	scanf("%s%d",&a,&k);
	le_ro(a,k,strlen(a));
	return 0;
}
void le_ro(char a[], int k,int len)
{
	char b;
	int i, j;
	for (i = 0;i < k;i++)
	{
		b = a[0];
		for (j = 0;j < len - 1;j++)
		{
			a[j] = a[j + 1];
		}
		a[len - 1] = b;
	}
	printf("%s", a);
}