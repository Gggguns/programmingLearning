#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int Sum = 0;
        for (auto& e : s)if (e == '1')Sum++;
        string Ret;
        for (int i = 0;i < s.size() - 1;i++)
        {
            if (i < Sum - 1)Ret += '1';
            else Ret += '0';
        }
        Ret += '1';
        return Ret;
    }
};
int main()
{
	return 0;
}