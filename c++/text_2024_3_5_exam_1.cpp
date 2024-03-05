#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Add(int num1, int num2) {
        int carry = (num1 & num2) << 1;
        int res = num1 ^ num2;
        while (carry)
        {
            int temcarry = (res & carry) << 1;
            res ^= carry;
            carry = temcarry;
        }
        return res;
    }
};
int main()
{
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;
    Solution s;
    cout << s.Add(num1, num2);
    return 0;
}