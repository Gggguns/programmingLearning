#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<unordered_map>
using namespace std;
int main() {
    string str1, str2;
    unordered_map<char, int> hash;
    cin >> str1 >> str2;
    for (auto e : str1) {
        hash[e]++;
    }
    bool flag = true;
    for (auto e : str2) {
        if (hash.count(e) == 0)flag = false;
        else {
            hash[e]--;
            if (hash[e] == 0)hash.erase(e);
        }
    }
    if (flag)cout << "Yes";
    else cout << "No";
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")