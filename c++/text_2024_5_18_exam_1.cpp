#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
bool is_prime(long long num) {
    if (num <= 1)return false;
    for (long long i = 2;i <= num / i;i++) {
        if (num % i == 0)return false;
    }
    return true;
}
int main() {
    long long a = 0, b = 0, n = 0;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if ((a == 1 && is_prime(b)) || (is_prime(a) && b == 1))cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}