#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cmath>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        long Total = pow(5, n) - 4;
        long Min = pow(4, n) + n - 4;
        cout << Total << ' ' << Min << endl;
    }
}