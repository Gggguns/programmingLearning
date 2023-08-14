#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s)
    {
        int i = 0;
        for (i = 0;i < s.size();i++)
        {
            char ch = s[i];
            int j = 0;
            for (j = 0;j < s.size();j++)
            {
                if (i != j)
                {
                    if (ch == s[j])
                        break;
                }
            }
            if (j == s.size())
                return i;
        }
        return -1;
    }
};

int main()
{
	return 0;
}