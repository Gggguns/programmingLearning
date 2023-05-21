#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_5_9_Date.h"
using std::endl;
using std::cout;
int main()
{
	Date d1;
	Date d2(2000, 4, 5);
	Date d3(2023);
	Date d4(2003, 5, 9);
	cout << (d2 < d4) << endl;
	//cout << d2 - d4 << endl;

	Date d5(2032, 2, 2);
	Date d6(2006, 10, 1);
	cout << d6 - d5 << endl;

	Date d7(2028, 5, 21);
	cout << d7  << endl;
	return 0;
}