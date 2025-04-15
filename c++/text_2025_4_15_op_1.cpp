#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size(), size = s.size();
        int left = -1, right = 0;
        unordered_map<char, int> hash1, hash2;
        for (auto e : t)hash1[e]++;
        int n = 0, ret = size + 1;
        string str;
        while (right < size)
        {
            char in = s[right++];
            hash2[in]++;
            if (hash2[in] <= hash1[in]) n++;
            if (n == m)
            {
                while (n == m)
                {
                    left++;
                    char out = s[left];
                    hash2[out]--;
                    if (hash2[out] < hash1[out]) n--;
                }
                if (ret > right - left)
                {
                    ret = right - left;
                    str = s.substr(left, ret);
                }
            }
        }
        return str;
    }
};
int main()
{
    Solution S;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    S.minWindow(s, t);
	return 0;
}