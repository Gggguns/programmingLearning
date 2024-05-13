#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<long long, int> Hash;
        for (auto e : nums) {
            Hash[e]++;
            if (Hash[e] >= 2)return true;
        }
        return false;
    }
};
int main() {
	return 0;
}