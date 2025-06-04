#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")return "0";
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = num1.size();
        int m = num2.size();
        vector<int> temp(n + m - 1);
        for (int i = 0; i < n; i++)
        {
            int a = num1[i] - '0';
            for (int j = 0; j < m; j++)
            {
                int b = num2[j] - '0';
                temp[i + j] += (a * b);
            }
        }
        int size = temp.size();
        int i = 0;
        string ret;
        while (i < size || carry)
        {
            if (i < size)carry += temp[i++];
            ret += (carry % 10 + '0');
            carry /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
	return 0;
}