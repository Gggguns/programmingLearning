#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    unordered_set<char> hash;
    for (auto e : str2)hash.insert(e);
    size_t i = 0;
    while (i < str1.size()) {
        if (hash.count(str1[i]))str1.erase(i, 1);
        else i++;
    }
    cout << str1;
    return 0;
}