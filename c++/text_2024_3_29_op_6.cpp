#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0, right = price.size() - 1;
        while (left < right)
        {
            if (price[left] + price[right] > target)
            {
                if (price[left] > price[right])left++;
                else right--;
            }
            else if (price[left] + price[right] == target)
            {
                break;
            }
            else
            {
                if (price[left] > price[right])right--;
                else left++;
            }

        }
        return { price[left],price[right] };
    }
};
int main()
{
	return 0;
}