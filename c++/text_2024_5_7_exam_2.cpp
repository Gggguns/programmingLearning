#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    long long n = 0, Max = -0xffffff, Sum = 0, left = -1, right = 0;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0;i < n;i++)cin >> v[i];
    while (right < n) {
        //进窗口
        Sum = Sum + v[right];
        right++;
        //判断
        if (Sum > Max)Max = Sum;
        //出窗口
        while (Sum < 0) {
            ++left;
            Sum = Sum - v[left];
        }
    }
    cout << Max;
    return 0;
}
// 64 位输出请用 printf("%lld")