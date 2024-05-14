#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> S;
        for (int i = 0;i < s.size();i++) {
            if (S.size()) {
                char ch = S.top();
                if (s[i] == ch) {
                    S.pop();
                    continue;
                }
            }
            S.push(s[i]);
        }
        string Ret;
        while (S.size()) {
            Ret = S.top() + Ret;
            S.pop();
        }
        return Ret;
    }
};
int main() {
    Solution s;
    s.removeDuplicates("abbaca");
	return 0;
}