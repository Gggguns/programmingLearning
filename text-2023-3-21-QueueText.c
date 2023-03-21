#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-21-Queue.h"
int main()
{
	Queue QU;
	QueueInit(&QU);
	QueuePush(&QU, 1);
	QueueDestroy(&QU);
	return 0;
}