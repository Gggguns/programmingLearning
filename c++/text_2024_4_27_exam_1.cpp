#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main() {
    string str, del;
    getline(cin, str);
    while (str == "")getline(cin, str);
    getline(cin, del);
    while (del == "")getline(cin, del);
    unordered_set<char> hash;
    for (auto e : del) {
        hash.insert(e);
    }
    for (size_t i = 0;i < str.size();) {
        if (hash.count(str[i]))str.erase(i, 1);
        else i++;
    }
    cout << str;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")