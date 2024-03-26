#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n)
    {
        long long arr[2] = { 0 };
        string str;
        for (int i = 0;i < n;i++)
        {
            getline(cin, str);
            while (str == "" || str == "\n")
                getline(cin, str);
            if (str.find("disconnect") != string::npos)
            {
                arr[0]--;
                arr[1]++;
            }
            else
            {
                if (arr[1] != 0)arr[1]--;
                arr[0]++;
            }
        }
        cout << arr[1] + arr[0] << endl;
    }
}
