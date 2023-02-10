#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Apart(long long num)
{
	if (0 <= num && num < 10)
		printf("%lld ", num);
	else
	{
		Apart(num / 10);
		printf("%lld ", num % 10);
	}

}
int main()
{
	long long num=0;
	scanf("%lld", &num);
	Apart(num);
	return 0;
}