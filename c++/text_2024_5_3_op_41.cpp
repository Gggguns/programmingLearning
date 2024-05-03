#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        int Count = 0;
        string str;
        string Res = "1";
        for (int i = 1;i < n;i++) {
            str = Res;
            Res.clear();
            char ch = '-';
            for (int j = 0;j < str.size();j++) {
                if (ch == '-') {
                    ch = str[j];
                    Count = 1;
                }
                while (j + 1 < str.size() && ch == str[j + 1]) {
                    Count++;
                    j++;
                }
                Res = Res + to_string(Count) + ch;
                Count = 0;
                ch = '-';
            }

        }
        return Res;
    }
};
int main() {
    return 0;
}