#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        s = ' ' + s;
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size));
        string retstr = "";
        int retsize = 0; 
        for (int i = size - 1; i > 0; i--)
        {
            for (int j = i; j < size; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i < 3)dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                else dp[i][j] = false;
                if (dp[i][j] && j - i + 1 > retsize)
                {
                    retsize = j - i + 1;
                    retstr = s.substr(i, retsize);
                }
            }
        }
        return retstr;
    }
};
int main()
{
	return 0;
}