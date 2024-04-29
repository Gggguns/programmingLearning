#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_set<int> hash;
        int Max = 0, cur = 0;
        int left = -1, right = 0, n = arr.size();
        while (right < n) {
            cur = arr[right];
            Max = max(Max, right - left - 1);
            while (hash.count(cur)) {
                left++;
                hash.erase(arr[left]);
            }
            right++;
            hash.insert(cur);
        }
        Max = max(Max, right - left - 1);
        return Max;
    }
};
int main() {
	return 0;
}