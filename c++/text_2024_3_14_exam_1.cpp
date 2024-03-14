#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

int main() {
    int n;
    while (cin >> n)
    {
        for (int i = 0;i < n;i++)
        {
            string str;
            while (str == "")
            {
                getline(cin, str);
            }
            if (str.find(' ') == string::npos && str.find(',') == string::npos)
            {
                cout << str;
            }
            else
            {
                cout << '"' << str << '"';
            }
            if (i < n - 1)cout << ", ";

        }
        cout << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")