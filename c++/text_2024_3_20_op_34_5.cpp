#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int Res = x ^ y;
        int RetSum = 0;
        while (Res)
        {
            if (Res & 1)RetSum++;
            Res = Res >> 1;
        }
        return RetSum;
    }
};
int main()
{
	return 0;
}