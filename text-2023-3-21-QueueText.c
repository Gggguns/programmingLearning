#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-21-Queue.h"
int main()
{
	Queue QU;
	QueueInit(&QU);
	QueuePush(&QU, 1);
	QueuePush(&QU, 2);
	QueuePush(&QU, 3);
	QueuePush(&QU, 4);
	QueuePush(&QU, 5);
	QueuePush(&QU, 6);
	while (!QueueEmpty(&QU))
	{
		printf("%d ", QueueFront(&QU));
		QueuePop(&QU);
	}
	QueueDestroy(&QU);
	return 0;
}