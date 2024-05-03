#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Solution {
public:
    string modifyString(string s) {
        int pos = 0, sz = s.size();
        while (pos < sz) {
            if (s[pos] == '?') {
                char ch = 'a';
                while (((pos - 1) >= 0 && s[pos - 1] == ch) || ((pos + 1) < s.size() && s[pos + 1] == ch))ch++;
                s[pos] = ch;
            }
            pos++;
        }
        return s;
    }
};
int main() {
	return 0;
}