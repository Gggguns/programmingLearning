#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    reverse(str.begin(), str.end());
    size_t begin = 0;
    size_t end = str.find(' ');
    while (end != string::npos) {
        reverse(str.begin() + begin, str.begin() + end);
        begin = end + 1;
        end = str.find(' ', begin);
    }
    reverse(str.begin() + begin, str.end());
    cout << str;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")