#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, long long> hash;
    string str1, str2;
    bool flag = true;
    cin >> str1 >> str2;
    for (auto& e : str1)hash[e]++;
    for (auto& e : str2) {
        hash[e]--;
        if (hash[e] < 0) {
            flag = false;
            break;
        }
    }
    if (flag)cout << "Yes";
    else cout << "No";
    return 0;
}