#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(int num) {
    if (num < 2)return 0;
    int Ret = 0;
    int r = 0;
    while (num) {
        r = num % 10;
        if (r == 2)Ret++;
        num /= 10;
    }
    return Ret;
}
int main() {
    int Left = 0, Right = 0;
    cin >> Left >> Right;
    int Sum = 0;
    for (int i = Left;i <= Right;i++) {
        Sum += Count(i);
    }
    cout << Sum << endl;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")