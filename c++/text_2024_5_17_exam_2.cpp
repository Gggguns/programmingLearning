#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    int T = 0;
    cin >> T;
    while (T--) {
        long long H = 0, Count = 0;
        cin >> H;
        long long num = 1, Res = 0;
        while (H) {
            H -= num;
            Count++;
            if (H % (2 * num) == 0) {
                num *= 2;
            }
        }
        cout << Count << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")