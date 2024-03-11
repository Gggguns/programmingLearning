#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string capitalizeTitle(string title) {
        transform(title.begin(), title.end(), title.begin(), ::tolower);
        size_t pos = title.find(' ');
        for (size_t i = 0;i < title.size();pos = title.find(' ', pos + 1))
        {
            if (pos == string::npos)pos = title.size();
            if (pos - i > 2)title[i] = toupper(title[i]);
            i = pos + 1;

        }
        return title;
    }
};
int main()
{
    string str;
    getline(cin, str);
    Solution s;
    cout << s.capitalizeTitle(str);
	return 0;
}