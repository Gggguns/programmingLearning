#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int BitSum(int n)
    {
        int Sum = 0;
        while (n)
        {
            Sum += pow(n % 10, 2);
            n /= 10;
        }
        return Sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = BitSum(n);
        while (slow != fast)
        {
            slow = BitSum(slow);
            fast = BitSum(BitSum(fast));
        }
        return slow == 1;
    }
};
void main()
{

}