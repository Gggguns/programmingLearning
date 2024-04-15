#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for (auto e : nums1) {
            hash[e] = 0;
        }
        for (auto e : nums2) {
            if (hash.count(e))
                hash[e]++;
        }
        vector<int> Ret;
        for (auto e : hash) {
            if (e.second > 0)Ret.push_back(e.first);
        }
        return Ret;
    }
};
int main()
{
	return 0;
}