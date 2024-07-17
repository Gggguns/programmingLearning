#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    size_t size = str.size();
    size_t pos = size - 1;
    int i = 0;
    while (pos != 0) {
        i++;
        if (i == 3) {
            str.insert(pos + str.begin(), ',');
            i = 0;
        }
        pos--;
    }
    cout << str;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")