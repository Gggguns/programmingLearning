#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = -1, right = 0;
        int n = fruits.size();
        unordered_map<int, int> hash;
        int Ret = 0;
        while (left < right && right < n) {
            hash[fruits[right++]]++;
            if (hash.size() > 2)Ret = max(Ret, right - left - 2);
            else Ret = max(Ret, right - left - 1);
            while (hash.size() > 2) {
                hash[fruits[++left]]--;
                if (hash[fruits[left]] == 0) {
                    hash.erase(fruits[left]);
                    break;
                }
            }

        }
        return Ret;
    }
};
int main()
{
	unordered_map<int, int> hash;
	hash[1]++;
	cout << hash[1];
	return 0;
}