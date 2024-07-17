#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    double weight = 0;
    char ch = ' ';
    cin >> weight >> ch;
    long long sum = 20;
    weight -= 1;
    if (ch == 'y')sum += 5;
    long long weight1 = 0;
    if (weight > 0)weight1 = (long long)weight;
    if (weight - weight1 > 0)weight1++;
    sum = sum + weight1;
    cout << sum;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")