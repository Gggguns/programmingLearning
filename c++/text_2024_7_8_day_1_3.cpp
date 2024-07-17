#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    for (long long i = 1;i < (long long)str.size() && i >= 0;) {
        if (str[i] == str[i - 1]) {
            str.erase(i - 1, 2);
            i = max((long long)0, i - 2);
        }
        else i++;
    }
    if (str.size() == 0)cout << 0;
    else cout << str;
    return 0;
}
