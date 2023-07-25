#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    int StrToInt(string& str) {
        std::string::iterator it = str.begin();
        int symbol = 1;
        if (*it == '+' || (*it) == '-')
        {
            if (*it == '-')
                symbol *= -1;
            it++;
        }
        if (0 <= (*it - '0') && (*it - '0') <= 9)
        {
            int ret = 0;
            while (it != str.end())
            {
                if ((0 <= (*it - '0') && (*it - '0') <= 9))
                    ret = ret * 10 + (*it - '0');
                else
                    return 0;
                it++;
            }
            return ret * symbol;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    string s;
    cin >> s;
    Solution p;
    cout << p.StrToInt(s) << endl;
	return 0;
}