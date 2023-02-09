#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void Swap(int* p1, int* p2)
{
	assert(p1 && p2);;
	int t;
	t = *p1;
	*p1 = *p2;
	*p2 = t;
	return;
}
int main()
{
	int num1, num2;
	scanf("%d%d",&num1,&num2);
	printf("交换前num1=%d num2=%d\n", num1, num2);
	Swap(&num1, &num2);
	printf("交换后num1=%d num2=%d\n", num1, num2);
	return 0;
}