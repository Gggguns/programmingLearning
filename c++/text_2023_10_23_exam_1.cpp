#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int EmptyBottle = 0;
    while (cin >> EmptyBottle)
    {
        if (EmptyBottle == 0)
        {
            break;
        }
        int AttainBottle = 0;
        int Sum = 0;
        while (EmptyBottle >= 3)
        {
            AttainBottle = EmptyBottle / 3;
            EmptyBottle %= 3;
            Sum += AttainBottle;
            EmptyBottle += AttainBottle;
            AttainBottle = 0;
        }
        if (EmptyBottle == 2)
        {
            Sum += 1;
        }
        cout << Sum << endl;
    }
    return 0;
}