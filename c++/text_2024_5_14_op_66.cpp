#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        //处理s字符串
        for (int i = 0;i < s.size();i++) {
            char ch = s[i];
            if (ch == '#') {
                if(st1.size())st1.pop();
                continue;
            }
            st1.push(ch);
        }
        //处理t字符串
        for (int i = 0;i < t.size();i++) {
            char ch = t[i];
            if (ch == '#') {
                if(st2.size())st2.pop();
                continue;
            }
            st2.push(ch);
        }
        if (st1.size() == st2.size()) {
            int sz = st1.size();
            while (sz--) {
                if (st1.top() == st2.top()) {
                    st1.pop();
                    st2.pop();
                }
                else return false;
            }
            return true;
        }
        else return false;
    }
};
int main() {
    Solution s;
    s.backspaceCompare("y#fo##f", "y#f#o##f");
    return 0;
}