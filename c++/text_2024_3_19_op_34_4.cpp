#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        int Size = n + 1;
        vector<int> Bits(Size);
        int Hight = 0;
        for (int i = 1;i < Size;i++)
        {
            if ((i & (i - 1)) == 0)Hight = i;
            Bits[i] = Bits[i - Hight] + 1;
        }
        return  Bits;
    }
};
int main()
{
	return 0;
}