#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        unordered_map<char, int> hash;
        for (auto e : s1)hash[e]++;
        for (auto e : s2)
        {
            hash[e]--;
            if (hash[e] < 0) return false;
        }
        return true;
    }
};
int main()
{
    return 0;
}