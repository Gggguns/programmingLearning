#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
    vector<string> v;
    string str1;
    getline(cin, str1);
    string str2;
    size_t pos1 = 0;
    size_t pos2 = 0;
    auto end = str1.begin();
    int size = 0;
    while (pos2 != string::npos && pos1 != string::npos)
    {
        pos2 = str1.find(' ', pos1);
        str2.clear();
        if (pos2 == string::npos)
        {
            end = str1.end();
        }
        else
        {
            end = str1.begin() + pos2;
        }
        str2.append(str1.begin() + pos1, end);
        pos1 = pos2 + 1;
        if (str2[0] == '"')
        {
            if (str2[str2.size() - 1] == '"')
            {
                str2.erase(str2.begin());
                str2.erase(str2.end() - 1);
                v.push_back(str2);
                continue;
            }
            pos2 = str1.find('"', pos2 + 1);
            str2.append(str1.begin() + pos1 - 1, str1.begin() + pos2);
            str2.erase(str2.begin());
            pos2 = str1.find(' ', pos2 + 1);
            pos1 = pos2 + 1;
        }
        v.push_back(str2);
    }

    cout << v.size() << endl;
    for (auto e : v)
    {
        cout << e << endl;
    }

    return 0;
}