#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    long long q = 0, a = 0, b = 0, c = 0;
    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        long long Min = min(min(a, b), c);
        long long score = 2 * Min;
        b -= Min;
        if (b)
            score = score + b - 1;
        cout << score << endl;
    }
    return 0;
}
