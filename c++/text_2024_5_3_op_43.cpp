#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //分三块区域
        int left = -1, cur = 0, right = nums.size();
        while (cur < right) {
            //红色
            if (nums[cur] == 0) {
                left++;
                swap(nums[cur], nums[left]);
                if (cur == left)cur++;
            }
            //白色
            else if (nums[cur] == 1)cur++;
            //蓝色
            else {
                right--;
                swap(nums[cur], nums[right]);
            }
        }
    }
};
int main() {
	return 0;
}
