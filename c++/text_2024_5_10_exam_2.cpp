#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
    string str;
    int n = 0;
    cin >> n;
    unordered_map<string, int> Hash;
    while (n--) {
        cin >> str;
        sort(str.begin(), str.end());
        Hash[str]++;
    }
    cout << Hash.size();
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")