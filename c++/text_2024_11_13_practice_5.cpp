#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<long long> nums(n);
    // ‰»Î
    for (int i = 0;i < n;i++)cin >> nums[i];
    //debug
    /*for (int i = 0;i < n;i++)cout << nums[i] << ' ';
    cout << endl;*/
    // *
    //   *
    vector<long long> f(n, 1);
    //   *
    // *
    vector<long long> g(n, 1);

    for (int i = 1;i < n;i++)
    {
        for (int j = 0;j < i;j++)
        {
            //µ›ºı
            if (nums[j] > nums[i])f[i] = max(f[j] + 1, f[i]);
            //µ›‘ˆ
            if (nums[j] < nums[i])g[i] = max(g[j] + 1, g[i]);
        }
    }
    long long maxRes = 0;
    for (int i = 1;i < n - 1;i++)
    {
        maxRes = max(maxRes, f[i] + g[i] - 1);
    }
    cout << maxRes;
    return 0;
}