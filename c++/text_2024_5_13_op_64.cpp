#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string Ret;
        int sz1 = num1.size(), sz2 = num2.size();
        int carry = 0;
        for (int i = 0;i < sz1;i++) {
            carry = 0;
            for (int j = 0;j < sz2;j++) {
                carry = carry + (num1[i] - '0') * (num2[j] - '0');
                if (j + i < Ret.size()) {
                    carry = carry + Ret[j + i] - '0';
                    Ret[j + i] = carry % 10 + '0';
                    carry /= 10;
                }
                else {
                    Ret += (carry % 10 + '0');
                    carry /= 10;
                    while (carry) {
                        Ret += (carry % 10 + '0');
                        carry /= 10;
                    }
                }
            }
            while (carry) {
                Ret += (carry % 10 + '0');
                carry /= 10;
            }
        }
        int i = Ret.size() - 1;
        while (i > 0) {
            if (Ret[i] == '0')Ret.erase(i, 1);
            else break;
            i--;
        }
        reverse(Ret.begin(), Ret.end());
        return Ret;
    }
};
int main() {
    Solution s;
    cout<<s.multiply("123", "456");
    return 0;
}