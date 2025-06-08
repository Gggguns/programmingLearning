#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        char op = '+';
        int size = s.size();
        int num = 0;
        char ch;
        int i = 0;
        while(i < size)
        {
            ch = s[i];
            if (ch == '-' || ch == '*' || ch == '/' || ch == '+')
            {
                op = ch;
                i++;
            }
            else if (ch >= '0' && ch <= '9')
            {
                while (i < size && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                if (op == '+')nums.push_back(num);
                else if (op == '-')nums.push_back(-num);
                else if (op == '*')nums.back() *= num;
                else if (op == '/')nums.back() /= num;
                num = 0;
            }
            else i++;
        }
        int sum = 0;
        for (auto e : nums)sum += e;
        return sum;
    }
};
int main()
{
    Solution s;
    string str1 = "1-1+1";
    cout << s.calculate(str1);
	return 0;
}