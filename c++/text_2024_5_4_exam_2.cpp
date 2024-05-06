#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<long long, long long> PLL;
struct Less {
    bool operator()(PLL p1,PLL p2) {
        if (p1.second < p2.second||(p1.second==p2.second&&p1.first>p2.first))return true;
        return false;
    }
};
int main() {
    long long n = 0, k = 0;
    cin >> n >> k;
    vector<PLL> v(n);
    for (long long i = 0;i < n;i++)cin >> v[i].first;
    for (long long i = 0;i < n;i++)cin >> v[i].second;
    sort(v.begin(), v.end(),Less());
    long long Suma = 0, Sumb = 0;
    long long i = n - k ;
    if (i < 0)i = 0;
    for (;i < n;i++) {
        Suma += v[i].first;
        Sumb += v[i].second;
    }
    cout << Suma << ' ' << Sumb;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")