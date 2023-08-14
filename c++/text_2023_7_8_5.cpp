#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int num = 0;
        for (auto n : nums)
        {
            num = num ^ n;

        }
        return num;
    }
};
void text_vector1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    v.push_back(4);
    v.push_back(6);
    Solution s;
    cout << s.singleNumber(v) << endl;
}
int main()
{
    text_vector1();
    return 0;
}