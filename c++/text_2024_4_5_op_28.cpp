#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> Pr(n, 1);
        auto Po = Pr;
        for (int i = 1;i < n;i++)Pr[i] = nums[i - 1] * Pr[i - 1];
        for (int i = n - 2;i >= 0;i--) {
            Po[i] = nums[i + 1] * Po[i + 1];
            Pr[i] *= Po[i];
        }
        Pr[n - 1] *= Po[n - 1];
        // vector<int> Ret;
        // for(int i=0;i<n;i++)Ret.push_back(Pr[i]*Po[i]);
        return Pr;
    }
};
int main()
{
	return 0;
}