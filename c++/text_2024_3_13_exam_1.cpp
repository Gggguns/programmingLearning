#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int Sum = 0;
        for (int Cur = 0;Cur < str1.size();)
        {
            if (str1.substr(Cur, str2.size()) == str2)
            {
                Sum++;
                Cur += str2.size();
                continue;
            }
            Cur++;
        }
        cout << Sum << endl;
    }
}