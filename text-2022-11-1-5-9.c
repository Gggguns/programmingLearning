#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num = 100;
	int Juage = 2,flat;
	while (num)
	{
		if (200 < num)
			break;
		flat = 1;
		Juage = 2;
		while (Juage)
		{
			if (num == Juage + 1)
			{
				break;
			}
			
			if (num % Juage == 0)
				{
					flat = 0;
					break;
				}
			Juage++;
		}
		if (flat == 1)
			printf("%d ", num);
		num++;
	}
	return 0;
}