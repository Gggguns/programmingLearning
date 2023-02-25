#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
    int scr = 1, dst = 1;
    while (scr < numsSize)
    {
        if (nums[scr] == nums[dst - 1])
            scr++;
        else
        {
            nums[dst] = nums[scr];
            dst++;
            scr++;
        }
    }
    return dst;
}
int main()
{
    int arr[2] = { 1,2 };
    int ret=removeDuplicates(arr, 2);
    printf("%d\n", ret);
    for (int i = 0;i < ret;i++)
    {
        printf("%d ", arr[i]);
    }
	return 0;
}