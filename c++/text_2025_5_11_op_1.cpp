#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int distance = numRows * 2 - 2;
        string ret;
        int n = s.size();
        if (numRows == 1) return s;
        // 第一行
        for (int i = 0; i < n; i += distance)ret += s[i];

        // 中间行
        for (int k = 1; k < numRows - 1; k++)
        {
            for (int i = k, j = distance - k; i < n || j < n; i += distance, j += distance)
            {
                if (i < n) ret += s[i];
                if (j < n) ret += s[j];
            }
        }

        // 最后一行
        for (int i = numRows - 1; i < n; i += distance)ret += s[i];
        return ret;
    }
};
int main()
{
    return 0;
}