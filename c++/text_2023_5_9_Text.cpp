#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_5_9_Data.h"
int main()
{
	Data d1;
	Data d2(2000, 4, 5);
	Data d3(2023);
	Data d4(d2);
	std::cout << (d2 < d4) << std::endl;
	return 0;
}