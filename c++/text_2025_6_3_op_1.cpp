#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int cur1 = a.size() - 1;
        int cur2 = b.size() - 1;
        int carry = 0;
        string ret;
        while (cur1 >= 0 || cur2 >= 0 || carry)
        {
            if (cur1 >= 0)carry += (a[cur1--] - '0');
            if (cur2 >= 0)carry += (b[cur2--] - '0');
            ret += (carry % 2 + '0');
            carry /= 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
    return 0;
}