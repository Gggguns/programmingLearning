#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int right = s.size() - 1;
        int left = 0;
        while (right > left)
        {
            std::swap(s[left], s[right]);
            right--;
            left++;
        }
    }
};
int main()
{
	return 0;
}