#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string Ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int szA = a.size(), szB = b.size();
        int i = 0;
        for (i = 0;i < szA && i < szB;i++) {
            carry = a[i] + b[i] - 2 * '0' + carry;
            Ret += (carry % 2 + '0');
            carry /= 2;
        }
        while (i < szA) {
            carry = carry + a[i] - '0';
            Ret += (carry % 2 + '0');
            carry /= 2;
            i++;
        }
        while (i < szB) {
            carry = carry + b[i] - '0';
            Ret += (carry % 2 + '0');
            carry /= 2;
            i++;
        }
        while (carry) {
            Ret += (carry % 2 + '0');
            carry /= 2;
        }
        reverse(Ret.begin(), Ret.end());
        return Ret;
    }
};
int main() {
    return 0;
}