#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Max(int n1, int n2)
{
	int ret=n1;
	if (n1 > n2)
		return ret;
	else if (n1 == n2)
		return ret;
	else
	{
		ret = n2;
		return ret;
	}

}
int main()
{
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	printf("%d",Max(n1,n2));
	return 0;
}