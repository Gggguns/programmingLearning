#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void reverse(int* star, int* end, int k)
{
    int tmp = 0;
    while (star < end)
    {
        tmp = *star;
        *star = *end;
        *end = tmp;
        end--;
        star++;
    }
}
void rotate(int* nums, int numsSize, int k)
{
    if (numsSize < k)
        k = k % numsSize;
    reverse(nums + numsSize - k, nums + numsSize - 1, k);
    reverse(nums, nums + numsSize - k - 1, k);
    reverse(nums, nums + numsSize - 1, numsSize / 2);
}
int main()
{
    int k = 0, nums[10] = {1,2,3,4,5,6,7,8,9,10},i=0;
    scanf("%d", &k);
    rotate(nums, 10, k);
    for (i = 0;i < 10;i++)
    {
        printf("%d ", nums[i]);
    }
	return 0;
}