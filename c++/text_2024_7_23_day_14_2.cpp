#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n = 0, sum = 0;
    cin >> n;
    vector<long long> nums(3 * n);
    for (auto& e : nums)cin >> e;
    sort(nums.begin(), nums.end());
    for (long long i = n;i < 3 * n;i += 2) {
        sum += nums[i];
    }
    cout << sum;
    return 0;
}
