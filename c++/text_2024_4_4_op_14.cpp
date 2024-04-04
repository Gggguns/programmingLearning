#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.size(), n = s.size();
        string str;
        int left = -1, right = 0;
        unordered_map<char, int> phash, shash;
        vector<int> v;
        for (auto e : p)phash[e]++;
        while (right < n) {
            char ch = s[right];
            if (phash.count(ch) == 0) {
                shash.clear();
                left = right;
                right++;
            }
            else {
                shash[ch]++;
                while (shash[ch] > phash[ch]) {
                    shash[s[++left]]--;
                }
                right++;
            }
            if ((right - left - 1) == len) {
                v.push_back(left + 1);
                shash[s[++left]]--;
            }
        }
        return v;
    }
};
int main()
{
	return 0;
}