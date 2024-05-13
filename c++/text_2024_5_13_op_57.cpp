#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> Hash;
        for (auto e : s1)Hash[e]++;
        for (auto e : s2) {
            if (Hash.count(e) == 0)return false;
            else {
                Hash[e]--;
                if (Hash[e] == 0)Hash.erase(e);
            }
        }
        if (Hash.size() == 0)return true;
        else return false;
    }
};
int main() {
	return 0;
}