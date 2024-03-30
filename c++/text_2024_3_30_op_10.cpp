#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = -1, right = 0;
        int len = -1;
        unordered_map<char, int> hash;
        while (left < right && right < n) {
            if (!hash.count(s[right])) {
                hash[s[right]] = right;
                right++;
            }
            else {
                len = max(len, right - left - 1);
                int des = hash[s[right]];
                while (left < des)hash.erase(s[++left]);
            }
        }
        int Res = hash.size();
        len = max(Res, len);
        if (len < 0)return n;
        else return len;
    }
};
int main()
{

    Solution s;
    cout<<s.lengthOfLongestSubstring("aab");
	return 0;
}