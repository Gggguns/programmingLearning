#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //便于查找
        unordered_set<int> hash;
        for (auto e : nums1)hash.insert(e);
        //去重
        unordered_set<int> nums;
        for (auto e : nums2)nums.insert(e);
        //得出结果
        vector<int> ret;
        for (auto e : nums)if (hash.count(e))ret.push_back(e);
        return ret;
    }
};
int main() {
    return 0;
}