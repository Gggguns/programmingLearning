#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        int size = strs.size();
        for (int i = 0; i < size; i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            hash[str].push_back(strs[i]);
        }
        vector<vector<string>> vv;
        for (auto e : hash)vv.push_back(e.second);
        return vv;
    }
};
int main()
{
    return 0;
}