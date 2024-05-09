#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    vector<int> Ret(n);
    for (int i = 0;i < n;i++)nums[i] = i + 1;
    sort(nums.begin(), nums.end());
    int sz = n / 2;
    int i = 0, pos = 0;
    for (i = 0, pos = 1;i < sz;i++, pos += 2)Ret[pos] = nums[i];
    for (pos = 0;i < n;i++, pos += 2)Ret[pos] = nums[i];
    auto it = Ret.begin();
    for (i = 0;i < n;i++)cout << Ret[i] << ' ';
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")