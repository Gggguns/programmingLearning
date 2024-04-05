#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int left = -1, right = 0;
        unordered_map<char, int> shash, thash;
        string Ret;
        for (auto e : t)thash[e]++;
        int Size = thash.size(), count = 0;
        while (right < n) {
            char ch = s[right++];
            shash[ch]++;
            if (shash[ch] == thash[ch])count++;
            char out = s[left + 1];
            while (shash[out] > thash[out] && left < right - 1) {
                left++;
                shash[out]--;
                out = s[left + 1];
            }
            if (count == Size) {
                int len = right - left - 1;
                if (Ret == "")Ret = s.substr(left + 1, len);
                else {
                    if (len < Ret.size()) {
                        Ret = s.substr(left + 1, len);
                    }
                }
                left++;
                shash[s[left]]--;
                count--;
            }
        }
        return Ret;
    }
};
int main()
{
	return 0;
}