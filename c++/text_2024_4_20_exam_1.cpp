#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    string solve(string s, string t) {
        if (s == "")return t;
        if (t == "")return s;
        string Ret;
        if (s.size() < t.size())s.swap(t);
        reverse(t.begin(), t.end());
        reverse(s.begin(), s.end());
        int i = 0, Carry = 0;
        for (i = 0;i < t.size();i++) {
            Carry = s[i] + t[i] - '0' * 2 + Carry;
            Ret += (Carry % 10) + '0';
            Carry /= 10;
        }
        for (;i < s.size();i++) {
            Carry = s[i] - '0' + Carry;
            Ret += (Carry % 10) + '0';
            Carry /= 10;
        }
        if (Carry)Ret += Carry + '0';
        reverse(Ret.begin(), Ret.end());
        return Ret;

    }
};
int main() {
    Solution s;
    s.solve("99999", "9999999");
    return 0;
}