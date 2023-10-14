#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    int i = 0;
    int size = 0;
    int Max = 0;
    for (i = 0;i < sizeof(int) * 8;i++)
    {
        if (num & (1 << i))
        {
            size++;
        }
        else
        {
            if (Max < size)
            {
                Max = size;
            }
            size = 0;
        }
    }
    cout << Max;
    return 0;
}
