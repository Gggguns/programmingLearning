#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//异或查找消失的数字
int missingNumber1(int* nums, int numsSize) {
    int mis = 0, i = 0;
    for (i = 0;i < numsSize;i++)
    {
        mis ^= nums[i];
    }
    for (i = 0;i <= numsSize;i++)
    {
        mis ^= i;
    }
    return mis;

}
//方法二
int missingNumber2(int* nums, int numsSize)
{
    int sum = 0, i = 0;
    sum = numsSize * (numsSize + 1) / 2;
    for (i = 0;i <numsSize;i++)
    {
        sum -= nums[i];
    }
    return sum;
}
int main()
{
    int ret1 = 0, ret2 = 0, i = 0, arr[5] = { 0,5,2,1,4 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    ret1= missingNumber1(arr, sz);
    ret2 = missingNumber2(arr, sz);
    printf("%d\n", ret1);
    printf("%d\n", ret2);
	return 0;
}