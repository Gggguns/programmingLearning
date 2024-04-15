#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int size = str.size();
    for (int i = 0;i < size;) {
        if (i + 1 < size) {
            if (str[i] == str[i + 1]) {
                str.erase(i, 2);
                size = str.size();
                i = max(i - 1, 0);
                continue;
            }
        }
        i++;
    }
    cout << str;
    return 0;
}