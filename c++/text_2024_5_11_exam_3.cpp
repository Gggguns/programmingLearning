#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int rZero = 0, wZero = 0, rOne = 0, wOne = 0, n = 0, Res = 0, left = -1, right = 0;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0;i < n;i++) {
        if (str[i] == '0')wZero++;
        else if (str[i] == '1')wOne++;
    }
    int sz = n / 2;
    while (right < n) {
        //进窗口
        if (right - left - 1 < sz) {
            if (str[right] == '1') {
                rOne++;
                wOne--;
            }
            else if (str[right] == '0') {
                rZero++;
                wZero--;
            }
            right++;
        }
        if (right - left - 1 == sz) {
            if (wZero == rZero && wOne == rOne) {
                if (left == -1 || right == n)Res++;
                else Res += 2;
            }
            left++;
            //出窗口
            if (str[left] == '0') {
                rZero--;
                wZero++;
            }
            else if (str[left] == '1') {
                rOne--;
                wOne++;
            }
        }
    }
    cout << Res;
    return 0;
}
// 64 位输出请用 printf("%lld")