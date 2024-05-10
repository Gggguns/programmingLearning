#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int h = 0, a = 0, H = 0, A = 0;
        cin >> h >> a >> H >> A;
        if (a >= H)cout << -1 << endl;
        else {
            int Min = H % a == 0 ? (H / a) : (H / a + 1);
            Min -= 1;
            Min *= A;
            int Res = h % Min == 0 ? (h / Min - 1) : h / Min;
            cout << Res << endl;
        }
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")