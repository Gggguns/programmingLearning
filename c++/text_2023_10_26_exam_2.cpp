#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v;
    v.resize(248);
    string str;
    cin >> str;
    string::iterator it = str.begin();
    size_t pos = 0;
    while (it != str.end())
    {
        pos = str.find(*it, 1);
        if (pos == string::npos)
        {
            cout << (*it);
            break;
        }
        else
        {
            while (pos != string::npos)
            {
                str.erase(str.begin() + pos);
                pos = str.find(*it, 1);
            }
            it = str.erase(str.begin());
        }
    }
    if (it == str.end())
    {
        cout << -1;
    }
    return 0;
}