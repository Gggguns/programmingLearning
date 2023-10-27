#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class MaxDivisor
{
public:
    int operator()(int x, int y)
    {
        int r = 0;
        if (y > x)
        {
            x ^= y;
            y ^= x;
            x ^= y;
        }
        while (y)
        {
            r = x % y;
            x = y;
            y = r;
        }
        return x;
    }
};
int main() {
    int MonsterNum = 0, PersonAbilityNum = 0, MonsterAbilityNum;
    while (cin >> MonsterNum >> PersonAbilityNum)
    {
        int Monsteri = 0;
        MaxDivisor M;
        for (Monsteri = 0;Monsteri < MonsterNum;Monsteri++)
        {
            cin >> MonsterAbilityNum;
            if (MonsterAbilityNum <= PersonAbilityNum)
            {
                PersonAbilityNum += MonsterAbilityNum;
            }
            else
            {
                PersonAbilityNum += M(PersonAbilityNum, MonsterAbilityNum);
            }
        }
        cout << PersonAbilityNum << endl;
    }
    return 0;
}