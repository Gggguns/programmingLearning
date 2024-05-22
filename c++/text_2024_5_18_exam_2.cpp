#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    long long n = 0, k = 0;
    cin >> n >> k;
    vector<int> nums(n);
    for (long long i = 0;i < n;i++)cin >> nums[i];
    sort(nums.begin(), nums.end());
    long long left = -1, right = 0, Max = -1;
    while (right < n) {
        right++;
        while (nums[right - 1] - nums[left + 1] > k) {
            left++;
        }
        if (nums[right - 1] - nums[left + 1] <= k)Max = max(Max, right - left - 1);
    }
    cout << Max;
    return 0;
}