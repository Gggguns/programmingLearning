#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int T = 0;
    cin >> T;
    int n = 0, k = 0;
    int won = 0, num = 0;
    string str;
    vector<int> Res;
    while (T--) {
        cin >> n >> k;
        cin >> str;
        won = 0;
        num = 0;
        for (int i = 0;i < n;i++) {
            if (str[i] == 'W') {
                won++;
                if (won >= 3)num += k;
                else num++;
            }
            else if (str[i] == 'L') {
                num--;
                won = 0;
            }
        }
        Res.push_back(num);
    }
    for (auto e : Res) {
        cout << e << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")