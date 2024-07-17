#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    long left = 0, right = 0, time = 0;
    cin >> left >> right;
    for (long i = left;i <= right;i++) {
        long num = i;
        while (num) {
            if (num % 10 == 2)time++;
            num /= 10;
        }
    }
    cout << time;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")