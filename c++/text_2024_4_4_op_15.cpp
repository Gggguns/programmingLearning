#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        int left = -1, right = 0;
        int n = s.size();
        string str;
        vector<int> Ret;
        unordered_map<string, int> shash, whash;
        for (auto e : words)whash[e]++;
        for (int i = 0;i < len;i++) {
            left = i - 1;
            right = i;
            shash.clear();
            while (right < n) {
                str = s.substr(right, len);
                if (whash.count(str) == 0) {
                    shash.clear();
                    left = right + len - 1;
                    right = left + 1;
                }
                else {
                    shash[str]++;
                    while (shash[str] > whash[str]) {
                        string DeStr = s.substr(left + 1, len);
                        shash[DeStr]--;
                        if (shash[DeStr] == 0)shash.erase(DeStr);
                        left += len;
                    }
                    right += len;
                }
                int SSum = right - left - 1;
                int WSum = len * words.size();
                if (SSum == WSum) {
                    Ret.push_back(left + 1);
                    shash[s.substr(left + 1, len)]--;
                    left += len;
                }
            }
        }
        return Ret;
    }
};
int main()
{
	return 0;
}
