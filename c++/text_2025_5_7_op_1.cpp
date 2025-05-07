#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        while (b)
        {
            result = a & b;
            a ^= b;
            b = result << 1;
        }
        return a;
    }
};
int main()
{
    return 0;
}