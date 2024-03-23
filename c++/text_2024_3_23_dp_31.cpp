#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> hash;
        hash[arr[0]] = 1;
        int MaxLen = 1;
        for (int i = 1;i < n;i++)
        {

            if (hash.count(arr[i] - difference))
            {
                hash[arr[i]] = hash[arr[i] - difference] + 1;
            }
            else hash[arr[i]] = 1;
            MaxLen = max(MaxLen, hash[arr[i]]);
        }
        return MaxLen;

    }
};
int main()
{
	unordered_map<int, int> hash;
	return 0;
}