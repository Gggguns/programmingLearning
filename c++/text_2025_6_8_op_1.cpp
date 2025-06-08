#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        string str;
        int size = s.size();
        int num = 0;
        for (int i = 0; i < size; i++)
        {
            char ch = s[i];
            if (ch == '*' || ch == '/' || ch == '-') {
                if (str.size())
                {
                    ch = str.back();
                    str.pop_back();
                    if (ch == '*')
                    {
                        num = nums.back() * num;
                        nums.pop_back();
                    }
                    else if (ch == '/')
                    {
                        num = nums.back() / num;
                        nums.pop_back();
                    }
                    else num = -num;
                }
                nums.push_back(num);
                num = 0;
                str.push_back(ch);
            }
            else if (ch >= '0' && ch <= '9')num = num * 10 + ch - '0';
        }
        if (str.size())
        {
            char ch = str.back();
            str.pop_back();
            if (ch == '*')
            {
                num = nums.back() * num;
                nums.pop_back();
            }
            else if (ch == '/')
            {
                num = nums.back() / num;
                nums.pop_back();
            }
            else num = -num;
            nums.push_back(num);
            num = 0;
        }
        int sum = 0;
        for (auto e : nums)sum += e;
        return sum;
    }
};
int main()
{
    Solution s;
    string str1 = "3 / 2";
    cout << s.calculate(str1);
	return 0;
}