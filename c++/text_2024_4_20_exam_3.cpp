#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string cal(char c, string& s) {
        int Carry = 0, Res = 0, n = s.size();
        Res = c - '0';
        if (Res == 0)return "0";
        string Ret;
        for (int i = 0;i < n;i++) {
            Carry = Res * (s[i] - '0') + Carry;
            Ret += (Carry % 10) + '0';
            Carry /= 10;
        }
        while (Carry) {
            Ret += (Carry % 10) + '0';
            Carry /= 10;
        }
        return Ret;
    }
    void add(string& Ret, string& tem) {
        if (Ret == "") {
            Ret.swap(tem);
            return;
        }
        if (tem == "0")return;
        if (Ret.size() > tem.size())Ret.swap(tem);
        int Carry = 0, i = 0;
        for (i = 0;i < Ret.size();i++) {
            Carry = Carry + Ret[i] + tem[i] - '0' * 2;
            tem[i] = (Carry % 10) + '0';
            Carry /= 10;
        }
        for (;i < tem.size();i++) {
            Carry = Carry + tem[i] - '0';
            tem[i] = (Carry % 10) + '0';
            Carry /= 10;
        }
        while (Carry) {
            tem += (Carry % 10 + '0');
            Carry /= 10;
        }
        Ret.swap(tem);
    }
    string solve(string s, string t) {
        if (s == "")return t;
        if (t == "")return s;
        if (s.size() < t.size())s.swap(t);
        reverse(t.begin(), t.end());
        reverse(s.begin(), s.end());
        int i = 0;
        string Ret, zera;
        for (i = 0;i < t.size();i++) {
            string tem;
            tem = cal(t[i], s);
            tem = zera + tem;
            add(Ret, tem);
            zera += '0';
        }
        reverse(Ret.begin(), Ret.end());
        return Ret;
    }
};
int main()
{
    Solution s;
    s.solve("100", "909");
	return 0;
}