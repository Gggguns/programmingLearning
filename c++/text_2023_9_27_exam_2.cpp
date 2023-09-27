#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    //获取元素个数
    int size = 0;
    cin >> size;
    //输入所有元素值
    int i = 0;
    long long sum = 0;
    long Max = 0;
    int num = 0;
    for (i = 0;i < size;i++)
    {
        cin >> num;
        if (i == 0)
        {
            sum = Max = num;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        sum += num;
        if (sum > Max)
        {
            Max = sum;
        }

    }

    cout << Max;
    return 0;
}