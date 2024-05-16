#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    string str;
    bool flag = false;
    long long q = 0;
    char ch = ' ';
    cin >> q;
    while (q--) {
        cin >> str;
        flag = false;
        int sz = str.size();
        for (int i = sz - 1;i >= 0;i--) {
            ch = str[i];
            if (ch <= '9' && ch >= '0' && ((ch - '0') % 2 == 0)) {
                str.erase(i, 1);
                flag = true;
                break;
            }
        }
        if (flag) {
            str += ch;
            cout << str << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")