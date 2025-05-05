#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isUnique(string astr) {
        int bitMap = 0;
        for (auto e : astr)
        {
            int i = e - 'a';
            if (bitMap >> i & 1) return false;
            else bitMap |= (1 << i);
        }
        return true;
    }
};
int main()
{
	return 0;
}