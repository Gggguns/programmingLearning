#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include<cmath>
using namespace std;

int main() {
    long num = 0;
    while (cin >> num)
    {
        int Ret = 0;
        for (int i = 2;i <= sqrt(num);i++)
        {
            if (num % i == 0)
            {
                while (num % i == 0)num /= i;
                Ret++;
            }

        }
        if (num != 1)Ret++;
        cout << Ret << endl;
    }
}
