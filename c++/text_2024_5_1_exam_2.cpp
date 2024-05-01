#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
unordered_map<int, int> cnt;
int n = 0, m = 0, hashMax = 0, num = 0;
int check(int x) {
    int group = 0;
    for (auto& e : cnt) {
        group = group + e.second / x + (e.second % x == 0 ? 0 : 1);
    }
    return group > m;
}

int main() {
    cin >> n >> m;
    //统计数量
    for (int i = 0;i < n;i++) {
        cin >> num;
        cnt[num]++;
        hashMax = max(hashMax, cnt[num]);
    }
    int left = 1, right = hashMax, mid = 0;
    if (cnt.size() > m)cout << -1 << endl;
    else
    {
        while (left < right) {
            mid = left + (right - left) / 2;
            if (check(mid))left = mid + 1;
            else right = mid;
        }
        cout << right << endl;
    }
    return 0;
}