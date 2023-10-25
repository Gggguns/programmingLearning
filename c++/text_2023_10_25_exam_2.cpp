#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ShowNum 4
using namespace std;

int main()
{
    int NumberOfSong = 0;
    cin >> NumberOfSong;
    string str;
    cin >> str;
    int Songi = 1, Showi = 1;
    int i = 0;
    while (i < str.size())
    {
        switch (str[i])
        {
        case 'U':
            if (Songi == 1)
            {
                Songi = NumberOfSong;
                if (NumberOfSong - ShowNum + 1 > 0)
                    Showi = NumberOfSong - ShowNum + 1;
            }
            else
            {
                if (Songi == Showi)
                {
                    Songi--;
                    Showi--;
                }
                else
                {
                    Songi--;
                }
                if (Songi == 0)
                {
                    Songi = NumberOfSong;
                    if (NumberOfSong - ShowNum + 1)
                        Showi = NumberOfSong - ShowNum + 1;
                }

            }
            break;
        case 'D':
            if (Songi == NumberOfSong)
            {
                Songi = 1;
                Showi = 1;
            }
            else
            {
                if (Songi - Showi == 3)
                {
                    Songi++;
                    Showi++;
                }
                else
                {
                    Songi++;
                }
                if (Songi > NumberOfSong)
                {
                    Songi = 1;
                    Showi = 1;
                }
            }
            break;
        default:
            break;
        }
        i++;
    }
    for (i = 0;i < ShowNum && Showi <= NumberOfSong;i++)
    {
        cout << Showi++;
        if (i < ShowNum - 1)
        {
            cout << ' ';
        }
    }
    cout << endl;
    cout << Songi;
    return 0;
}