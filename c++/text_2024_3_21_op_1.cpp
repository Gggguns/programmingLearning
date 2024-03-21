#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int End=0,Cur=0;
		while(Cur<nums.size())
		{
			if(nums[Cur])
			{
				swap(nums[End],nums[Cur]);
				End++;
			}
			Cur++; 
		}
    }
};
int main()
{
	return 0;
}
