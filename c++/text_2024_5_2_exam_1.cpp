#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string formatString(string str, vector<char>& arg) {
        size_t pos = str.find("%s");
        size_t  i = 0;
        while (pos != string::npos) {
            str[pos++] = arg[i++];
            str.erase(pos, 1);
            pos = str.find("%s", pos);
        }
        size_t n = arg.size();
        while (i < n)str += arg[i++];
        return str;
    }
};
int main() {
	return 0;
}