#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string compressString(string param) {
        if (param == "")return param;
        int Count = 0;
        char ch = '-';
        size_t pos = 0;
        string Ret;
        for (pos = 0;pos < param.size();pos++) {
            if (ch == '-') {
                Count = 1;
                ch = param[pos];
            }
            else if (param[pos] == ch)Count++;
            else {
                Ret += ch;
                if (Count > 1)Ret += to_string(Count);
                ch = param[pos];
                Count = 1;
            }
        }
        Ret += ch;
        if (Count > 1)Ret += to_string(Count);
        return Ret;
    }
};
int main() {
	return 0;
}