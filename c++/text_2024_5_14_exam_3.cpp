#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    long long n = 0, p = 0;
    cin >> n >> p;
    long long up = 0x3ffffff, down = -0x3ffffff;
    vector<long long> nums(n);
    for (auto& e : nums)cin >> e;
    sort(nums.begin(), nums.end());
    long long Max = -1;
    long long left = -1, right = 0;
    while (right < n) {
        right++;
        long long gap = nums[right - 1] - nums[left + 1];
        if (gap <= 2 * p) {
            Max = max(Max, right - left - 1);
        }
        else {
            while (gap > 2 * p) {
                left++;
                gap = nums[right - 1] - nums[left + 1];
            }
        }
    }
    cout << Max;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")