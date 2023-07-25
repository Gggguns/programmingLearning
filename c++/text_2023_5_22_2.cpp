#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int carry = 0;
        int end1=0;
        int end2=0;
        while (num1.size() != 0 || num2.size() != 0)
        {
            if (num1.size())
                end1 = *(num1.end() - 1) - '0';
            else
                end1 = 0;
            if (num2.size())
                end2 = *(num2.end() - 1) - '0';
            else
                end2 = 0;
            int result = end1 + end2  + carry;
            carry = result / 10;
            result = result % 10;
            ret.push_back(result + '0');
            if (num1.size())
                num1.pop_back();
            if (num2.size())
                num2.pop_back();
        }
        if(carry)
        ret += (carry + '0');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{

	string s1;
	string s2;
    cin >> s1;
    cin >> s2;
    Solution p;
    string ret=p.addStrings(s1, s2);
	cout << ret << endl;
	return 0;
}