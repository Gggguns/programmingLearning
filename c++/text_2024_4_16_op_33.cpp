#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isUnique(string astr) {
        int len = astr.size();
        if (len > 26)return false;
        int bitMap = 0;
        for (auto e : astr) {
            if (((bitMap >> (e - 'a')) & 1) == 1)return false;
            bitMap |= (1 << (e - 'a'));
        }
        return true;
    }
};
int main()
{
	int n = 72;
	int res = n & (~n+1);
	cout << res;
	return 0;
}