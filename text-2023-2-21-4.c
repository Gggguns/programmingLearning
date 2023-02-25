#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
    int* begin = nums;
    if (numsSize == 0)
        return numsSize;
    while (begin < nums + numsSize - 1)
    {
        if (*begin == val)
        {
            *begin = *(nums + numsSize - 1);
            numsSize--;
            continue;
        }
        begin++;
    }
    if (*(nums + numsSize - 1) == val)
        numsSize--;
    return numsSize;
}
int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,5 };
    int ret = removeElement(arr, 10, 5);
    for (int i = 0;i < ret;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}