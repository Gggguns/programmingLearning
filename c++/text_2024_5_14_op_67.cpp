#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        long long sz = s.size();
        vector<long long> st;
        long long i = 0;
        char op = '+';
        while (i < sz) {
            if (s[i] == ' ')i++;
            else if (s[i] >= '0' && s[i] <= '9') {
                long long num = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i++] - '0';
                }
                if (op == '+')st.push_back(num);
                else if (op == '*')st.back() *= num;
                else if (op == '/')st.back() /= num;
                else if (op == '-')st.push_back(-num);
            }
            else {
                op = s[i];
                i++;
            }
        }
        long long Ret = 0;
        for (auto e : st)Ret += e;
        return Ret;
    }
};
int main() {
    Solution s;
    cout<<s.calculate(" 3/2 ");
	return 0;
}