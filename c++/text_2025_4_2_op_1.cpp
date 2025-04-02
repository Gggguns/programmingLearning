#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Solution {
public:
    int bitSum(int n)
    {
        int Sum = 0;
        while (n)
        {
            int r = n % 10;
            Sum = Sum + r * r;
            n = n / 10;
        }
        return Sum;
    }
    bool isHappy(int n) {
        int slow = bitSum(n);
        int fast = bitSum(bitSum(n));
        while (slow != fast)
        {
            slow = bitSum(slow);
            fast = bitSum(bitSum(fast));
        }
        return slow == 1;
    }
};
int main()
{
    Solution s;
    s.isHappy(2);
	return 0;
}