#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    int StrToInt(string str)
    {
        int sign = 1;
        char ch = str[0];
        if (ch != '-' && ch != '+' && (ch < '0' || ch>'9'))
        {
            return 0;
        }
        if (ch == '-')
        {
            sign = -1;
        }
        int i = 0;
        if (ch == '-' || ch == '+')
        {
            i++;
        }
        int sum = 0;
        for (;i < str.size();i++)
        {
            if (str[i] < '0' || str[i]>'9')
            {
                return 0;
            }
            sum += (str[i] - '0');
            if (i < str.size() - 1)
            {
                sum *= 10;
            }
        }
        return sum * sign;
    }
};
int main()
{
    return 0;
}