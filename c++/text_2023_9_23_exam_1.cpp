#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iterator>
#include<vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int i = 0;
    int count = 0;
    int Great = 0;
    int prevnum = 0;
    int postnum = 0;
    for (i = 0;i < n;i++)
    {
        if (i == 0)
        {
            cin >> prevnum >> postnum;
        }
        else
        {
            prevnum = postnum;
            cin >> postnum;
        }
        if (prevnum < postnum)
        {
            if (Great == 1)
            {
                count++;
                Great = 0;
            }
            else
            {
                Great = -1;
            }
        }
        if (prevnum > postnum)
        {
            if (Great == -1)
            {
                count++;
                Great = 0;
            }
            else
            {
                Great = 1;
            }
        }

    }
    cout << count + 1;
}