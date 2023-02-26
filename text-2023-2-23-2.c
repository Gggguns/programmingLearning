#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int end1 = m, end2 = n;
    int dst = nums1Size;
    while (end1 && end2)
    {
        if (nums1[end1 - 1] < nums2[end2 - 1])
            nums1[--dst] = nums2[--end2];
        else
            nums1[--dst] = nums1[--end1];
    }
    while (end2)
    {
        nums1[--dst] = nums2[--end2];
    }
}
int main()
{
    int arr1[6] = { 1,2,3,0,0,0 };
    int arr2[3] = { 2,2,2 };
    merge(arr1, 6, 3, arr2, 3, 3);
    for (int i = 0;i < 6;i++)
    {
        printf("%d ", arr1[i]);
    }
	return 0;
}