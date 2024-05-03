#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        int sz = s.size();
        string Ret;
        int gap = (numRows - 1) * 2;
        for (int i = 0;i < numRows;i++) {
            int pos = i;
            int second = gap - i;
            while (pos < sz) {
                Ret += s[pos];
                if (i < numRows - 1 && i>0 && second < sz) {
                    Ret += s[second];
                    second += gap;
                }
                pos += gap;
            }
        }
        return Ret;
    }
};
int main() {
    Solution s;
    s.convert("PAYPALISHIRING", 3);
	return 0;
}