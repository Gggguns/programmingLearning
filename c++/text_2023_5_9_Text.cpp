#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_5_9_Date.h"
int main()
{
	Date d1;
	Date d2(2000, 4, 5);
	Date d3(2023);
	Date d4(d2);
	std::cout << (d2 < d4) << std::endl;
	return 0;
}