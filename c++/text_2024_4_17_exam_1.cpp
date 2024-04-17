#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string str, res;
    while (cin >> str) {
        res += toupper(str[0]);
    }
    cout << res;
    return 0;
}