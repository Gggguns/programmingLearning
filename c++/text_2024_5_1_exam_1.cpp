#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cmath>
using namespace std;
bool absolution(long long num) {
    if (num == 0)return false;
    long long a = sqrt(num);
    return a * a == num;
}
int main() {
    long long num = 0;
    cin >> num;
    long long Prev = -1, Post = -1;
    for (long long i = 0;;i++) {
        if (absolution(num - i))Prev = num - i;
        if (absolution(num + i))Post = num + i;
        if (Prev != -1 || Post != -1)break;
    }
    if (Prev != -1)cout << Prev;
    else if (Post != -1)cout << Post;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
