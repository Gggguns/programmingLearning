#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    long long num = 0, Count = 1;
    vector<long long> nums(n);
    int sign = 0;
    for (long long i = 0;i < n;i++) {
        cin >> nums[i];
    }
    long long begin = nums[0];
    for (long long i = 1;i < n;i++) {
        long long Res = nums[i] - nums[i - 1];
        if (sign == 0)sign = Res;
        else if ((sign < 0 && Res>0) || (sign > 0 && Res < 0)) {
            Count++;
            sign = 0;
        }
    }
    cout << Count;
    return 0;
}
// 64 位输出请用 printf("%lld")
// 64 位输出请用 printf("%lld")