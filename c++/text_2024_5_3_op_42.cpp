#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> cnt, hash;
        string str = "croak";
        int sz = str.size();
        for (int i = 0;i < sz;i++)hash[str[i]] = i;
        sz = croakOfFrogs.size();
        for (int i = 0;i < sz;i++) {
            char ch = croakOfFrogs[i];
            if (hash.count(ch)) {
                if (ch == 'c') {
                    cnt[ch]++;
                    if (cnt['k'])cnt['k']--;
                }
                else {
                    cnt[ch]++;
                    cnt[str[hash[ch] - 1]] --;
                    if (cnt[str[hash[ch] - 1]] < 0)return -1;
                }
            }
        }
        for (auto e : cnt) {
            if (e.first != 'k' && e.second)return -1;
        }
        return cnt['k'];
    }
};
int main() {
    Solution s;
    s.minNumberOfFrogs("croakcroak");
	return 0;
}