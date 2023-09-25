#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    string s;
    string str;
    cin >> s;
    int Max = 0;
    int len=0;
    string::iterator it = s.begin();
    while (it != s.end())
    {
        if (it == s.begin())
        {
            len++;
        }
        else if ((('a' <= *it && *it <= 'z') && 'a' <= *(it - 1) && *(it - 1) <= 'z') || (('0' <= *it && *it <= '9') && '0' <= *(it - 1) && *(it - 1) <= '9'))
        {
            len++;
        }
        else
        {
            if (len > Max)
            {
                Max = len;
                str.clear();
                str.append(it - Max, it);
            }
            len = 1;
        }
        
        it++;
    }
    if (len > Max)
    {
        Max = len;
        str.clear();
        str.append(it - Max, it);
    }
    cout << str;
    return 0;
}