#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        char ch;
        int size = strs.size();
        string str = strs[0];
        for (size_t i = 0; i < str.size(); i++)
        {
            ch = str[i];
            for (int j = 1; j < size; j++)
            {
                if (i < strs[j].size() && strs[j][i] == ch)continue;
                else return prefix;
            }
            prefix += ch;
        }
        return prefix;
    }
};
int main()
{
	return 0;
}