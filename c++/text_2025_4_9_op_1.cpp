#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int size = s.size();
        int left = -1, right = 0;
        int length = 0;
        while (right < size)
        {
            char ch = s[right];
            // �봰
            if (hash[ch] == 0)
            {
                hash[ch]++;
                right++;
            }
            else
            {
                // ����
                length = max(length, right - left - 1);
                while (hash[ch])
                {
                    left++;
                    hash[s[left]]--;
                }
            }
        }
        length = max(length, right - left - 1);
        return length;
    }
};
int main()
{
    return 0;
}