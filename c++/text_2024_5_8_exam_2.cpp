#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<set>
using namespace std;

int main() {
    int num = 0, sz = 0, n = 0, i = 0;
    set<int> S;
    cin >> n;
    sz += n;
    cin >> n;
    sz += n;
    for (i = 0;i < sz;i++) {
        cin >> num;
        S.insert(num);
    }
    i = 0;
    for (auto& e : S) {
        cout << e;
        if (i < sz - 1)cout << ' ';
        i++;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")