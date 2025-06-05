#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        int size = s.size();
        string ret;
        for (int i = 0; i < size; i++)
        {
            char ch = s[i];
            if (ret.size() && ch == ret.back())ret.pop_back();
            else ret += ch;
        }
        return ret;
    }
};
int main()
{
    return 0;
}