#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int pos = str.size();
    pos -= 3;
    while (pos >= 1) {
        str.insert(pos, ",");
        pos -= 3;
    }
    cout << str;
    return 0;
}
