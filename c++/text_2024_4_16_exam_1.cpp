#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    double num = 0;
    char ch;
    cin >> num >> ch;
    int Sum = 0;
    int Integer = (int)num;
    if (num - Integer > 0)Integer++;
    Sum = Integer + 19;
    if (ch == 'y')Sum += 5;
    cout << Sum;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")