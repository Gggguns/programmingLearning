#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        while (--n)
        {
            char ch = str[0];
            int count = 1;
            string result;
            for (size_t i = 1; i < str.size(); i++)
            {
                if (ch != str[i])
                {
                    result += to_string(count);
                    result += ch;
                    ch = str[i];
                    count = 0;
                }
                count++;
            }
            result += to_string(count);
            result += ch;
            str = result;
        }
        return str;
    }
};
int main()
{
    return 0;
}