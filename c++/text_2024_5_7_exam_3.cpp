#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    string temp = str;
    reverse(temp.begin(), temp.end());
    if (temp == str) {
        char ch = str[0];
        size_t sz = 0;
        for (auto e : str)
            if (e == ch)sz++;
            else break;
        if (sz == str.size())cout << 0;
        else {
            str.pop_back();
            cout << str.size();
        }
    }
    else cout << str.size();
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")