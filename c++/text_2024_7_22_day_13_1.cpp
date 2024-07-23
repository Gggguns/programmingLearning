#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    while (n--) {
        long long size = 0, k = 0, sum = 0;
        cin >> size >> k;
        string str;
        cin >> str;
        int flag = 0;
        for (long long i = 0;i < size;i++) {
            if (str[i] == 'W') {
                flag++;
                if (flag > 2)sum += k;
                else sum++;
            }
            else {
                sum--;
                flag = 0;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")