#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//µÝ¹é
int Fac(int num)
{
	if (num == 1)
		return 1;
	else if (num == 0)
		return 0;
	else
		return num * Fac(num - 1);
}
int main()
{
	int num,fac=1;
	scanf("%d", &num);
	printf("%d\n", Fac(num));
	if (num == 0)
		printf("%d", 0);
	else 
	{//Ñ­»·
		while (num)
		{
			fac = fac * num;
			num--;
		}
		printf("%d\n", fac);
	}
	
	return 0;
}