#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{

    long long num = 0;
    while (scanf("%lld", &num) != EOF)
    {
        int i = 0;
        int count = 0;
        for (i = 0;i < sizeof(int) * 8;i++)
        {
            if (num & (1 << i))
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}