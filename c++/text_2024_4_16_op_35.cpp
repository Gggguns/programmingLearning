#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        int Carry = (a & b) << 1;
        int Res = a ^ b;
        int Tem = 0;
        while (Carry) {
            Tem = Res ^ Carry;
            Carry = (Carry & Res) << 1;
            Res = Tem;
        }
        return Res;
    }
};
int main()
{
	return 0;
}