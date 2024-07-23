#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:

    int maxLength(vector<int>& arr) {
        long long ret = 0;
        long long left = -1, right = 0, n = arr.size();
        unordered_set<int> hash;
        while (right < n) {
            //入窗口
            while (right < n && hash.count(arr[right]) == 0) {
                hash.insert(arr[right]);
                right++;
            }
            //判断
            ret = max(ret, right - left - 1);
            //出窗口
            while (right < n && hash.count(arr[right])) {
                left++;
                hash.erase(arr[left]);
            }
        }
        return ret;
    }
};

int main() {
    return 0;
}