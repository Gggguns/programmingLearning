#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long k = 0, Size = 0;
vector<long long> nums;
long long mSum(long long left, long long right)
{
    long long Sum = 0, maxSum = 0;
    int size = 0;
    while (right < Size)
    {
        //入窗口
        while (right < Size && size < k)
        {
            Sum += nums[right];
            size++;
            right += 2;
        }
        //判断
        if (left == -1 || left == -2 || Sum > maxSum)maxSum = Sum;
        //出窗口
        left += 2;
        Sum -= nums[left];
        size--;
    }
    return maxSum;
}
int main()
{
    long long maxSum = 0, Sum1 = 0, Sum2 = 0;
    cin >> Size;
    nums.resize(Size);
    for (long long i = 0;i < Size;i++)
    {
        cin >> nums[i];
    }
    cin >> k;
    /*for (long long i = 0;i < Size;i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;*/
    Sum1 = mSum(-2, 0);
    Sum2 = mSum(-1, 1);
    maxSum = max(Sum1, Sum2);
    cout << maxSum;
    return 0;
}