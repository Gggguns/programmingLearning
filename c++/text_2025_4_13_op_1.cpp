#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = -1, right = 0;
        int n = s.size(), m = p.size();
        vector<int> ret;
        int count = 0;
        unordered_map<char, int> hash1, hash2;
        for (auto e : p)hash1[e]++;
        while (right < n)
        {
            char in = s[right];
            hash2[in]++;
            right++;
            if (hash2[in] <= hash1[in]) count++;
            if (right - left - 1 > m)
            {
                char out = s[++left];
                hash2[out]--;
                if (hash2[out] < hash1[out]) count--;
            }
            if (count == m) ret.push_back(left + 1);
        }
        return ret;
    }
};
int main()
{
    string s, p;
    s = "cbaebabacd";
    p = "abc";
    Solution S;
    S.findAnagrams(s, p);
    return 0;
}