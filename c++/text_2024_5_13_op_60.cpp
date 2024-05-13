#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> Hash;
        vector<vector<string>> Ret;
        string str;
        for (auto& e : strs) {
            str = e;
            sort(str.begin(), str.end());
            if (Hash.count(str) == 0) {
                Hash[str] = Hash.size();
                Ret.push_back(vector<string>(1, e));
            }
            else {
                Ret[Hash[str]].push_back(e);
            }
        }
        return Ret;
    }
};
int main() {
	return 0;
}