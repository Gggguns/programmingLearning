#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int SumPiont = 0;
    int SignNum = 0, NumNum = 0, CapitalNum = 0, LowNum = 0;
    int i = 0;
    for (i = 0;i < str.size();i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            NumNum++;
        }
        else if ('a' <= str[i] && str[i] <= 'z')
        {
            LowNum++;
        }
        else if ('A' <= str[i] && str[i] <= 'Z')
        {
            CapitalNum++;
        }
        else
        {
            SignNum++;
        }
    }
    //密码长度得分
    if (str.size() <= 4)
    {
        SumPiont += 5;
    }
    else if (str.size() >= 8)
    {
        SumPiont += 25;
    }
    else
    {
        SumPiont += 10;
    }
    //字母得分
    if (CapitalNum && LowNum)
    {
        SumPiont += 20;
    }
    else if (CapitalNum || LowNum)
    {
        SumPiont += 10;
    }
    else
    {
        SumPiont += 0;
    }
    //数字得分
    if (NumNum == 0)
    {
        SumPiont += 0;
    }
    else if (NumNum == 1)
    {
        SumPiont += 10;
    }
    else
    {
        SumPiont += 20;
    }
    //符号得分
    if (SignNum == 0)
    {
        SumPiont += 0;
    }
    else if (SignNum == 1)
    {
        SumPiont += 10;
    }
    else
    {
        SumPiont += 25;
    }
    //奖励得分
    if (CapitalNum && LowNum && SignNum && NumNum)
    {
        SumPiont += 5;
    }
    else if (SignNum && NumNum && (CapitalNum || LowNum))
    {
        SumPiont += 3;
    }
    else if (NumNum && (CapitalNum || LowNum))
    {
        SumPiont += 2;
    }
    //根据得分评定标准
    if (SumPiont >= 90)
    {
        cout << "VERY_SECURE";
    }
    else if (SumPiont >= 80)
    {
        cout << "SECURE";
    }
    else if (SumPiont >= 70)
    {
        cout << "VERY_STRONG";
    }
    else if (SumPiont >= 60)
    {
        cout << "STRONG";
    }
    else if (SumPiont >= 50)
    {
        cout << "AVERAGE";
    }
    else if (SumPiont >= 25)
    {
        cout << "WEAK";
    }
    else
    {
        cout << "VERY_WEAK";
    }
    cout <<endl<< SumPiont;
    return 0;
}