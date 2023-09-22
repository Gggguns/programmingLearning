#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    //获取队伍数量
    int n = 0;
    cin >> n;
    //获取所有参赛人员的水平值
    vector<int> v;
    int i = 0;
    int account = 3 * n;
    int a_i = 0;
    for (i = 0;i < account;i++)
    {
        cin >> a_i;
        v.push_back(a_i);
    }
    //对所有水平值进行排序
    sort(v.begin(), v.end());
    //计算最大值
    long count = 0;
    for (int i = 1;i <= n;i++)
    {

        count += v[account - 2 * i];
    }
    cout << count;
}