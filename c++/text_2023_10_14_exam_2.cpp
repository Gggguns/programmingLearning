#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<math.h>
using namespace std;
class Prime
{
public:
    bool operator()(int num)
    {
        int i = 0;
        if (num == 1)
            return false;
        for (i = 2;i <= sqrt(num);i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    cin >> num1;
    int prime1 = 0;
    int prime2 = num1;
    int i = 0;
    Prime P;
    for (i = 2;i <= num1 / 2;i++)
    {
        num2 = i;
        num3 = num1 - i;
        if (P(num2) && P(num3))
        {
            if ((num3 - num2) < (prime2 - prime1))
            {
                prime1 = num2;
                prime2 = num3;
            }
        }
    }
    cout << prime1 << endl << prime2;
    return 0;
}