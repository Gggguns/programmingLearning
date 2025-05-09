#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if ((i - 1 >= 0 && ch == s[i - 1]) || (i + 1 < n && ch == s[i + 1]))continue;
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};
int main()
{
    Solution s;
    string str = "??yw?ipkj?";
    s.modifyString(str);
    return 0;
}