#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<set>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    long long num = 0;
    set<int> S;
    for (int i = 0;i < n;i++) {
        cin >> num;
        while (num % 2 == 0)num /= 2;
        S.insert(num);
    }
    if (S.size() > 1)cout << "NO";
    else cout << "YES";
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")