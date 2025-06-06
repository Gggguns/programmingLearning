#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        int step = words[0].size();
        int left = -1, right = 0;
        int size = s.size();
        int n = 0, m = words.size();
        unordered_map<string, int> hash1, hash2;
        for (auto e : words)hash2[e]++;
        string substring;
        int length = step * m;
        for (int i = 0; i < step; i++)
        {
            right = i;
            left = i - 1;
            n = 0;
            hash1.clear();
            while (right < size)
            {
                // slide  the whidown
                substring = s.substr(right, step);
                hash1[substring]++;
                right += step;
                if (hash1[substring] <= hash2[substring])n++;
                if (right - left - 1 > length)
                {
                    left++;
                    substring = s.substr(left, step);
                    hash1[substring]--;
                    if (hash1[substring] < hash2[substring])n--;
                    left += (step - 1);
                }
                if (m == n) ret.push_back(left + 1);
            }
        }
        return ret;
    }
};
int main()
{
    Solution S;
    string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = { "fooo","barr","wing","ding","wing" };
    S.findSubstring(str, words);
    return 0;
}