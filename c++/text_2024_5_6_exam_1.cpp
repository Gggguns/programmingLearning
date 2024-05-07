#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long Gcd(long long a, long long b) {
    long long r = 0;
    if (b > a)swap(a, b);
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    long long n = 0, x = 0, num = 0;
    cin >> n >> x;
    for (long long i = 0;i < n;i++) {
        cin >> num;
        if (x >= num)x += num;
        else x += (Gcd(x, num));
    }
    cout << x;
    return 0;
}