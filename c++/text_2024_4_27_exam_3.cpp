#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
    int n = 0;
    string str;
    cin >> n >> str;
    unordered_map<string, long long> hash;
    for (int i = 0;i < n;i++) {
        if (str[i] == 's')hash["s"]++;
        else if (str[i] == 'h')hash["sh"] += hash["s"];
        else if (str[i] == 'y')hash["shy"] += hash["sh"];
    }
    cout << hash["shy"];
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")