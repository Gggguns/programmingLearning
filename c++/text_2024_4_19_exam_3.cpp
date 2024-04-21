#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        int a = 0, b = 0;
        int i = 1;
        while (n--) {
            b = (a + m) % i;
            a = b;
            i++;
        }
        return b;
    }
};
int main()
{
	return 0;
}