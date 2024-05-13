#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string Ret;
        int sz = strs.size();
        size_t lenth = 0x3fffffff;
        for (int i = 0;i < sz;i++)lenth = min(lenth, strs[i].size());
        for (size_t i = 0;i < lenth;i++) {
            char ch;
            for (int j = 0;j < sz;j++) {
                if (j == 0)ch = strs[j][i];
                else {
                    if (strs[j][i] != ch)return Ret;
                }
            }
            Ret += ch;
        }
        return Ret;
    }
};
int main() {
	return 0;
}