#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    long long length = 0;
    cin >> length;
    string str1, str2;
    cin >> str1 >> str2;
    long long res = -1;
    unordered_map<string, long long> hash;
    for (long long i = 0;i < length;i++) {
        string str;
        cin >> str;
        hash[str] = i;
        if (hash.count(str1) && hash.count(str2)) {
            if (res == -1)res = abs(hash[str2] - hash[str1]);
            else res = min(res, abs(hash[str2] - hash[str1]));
        }
    }
    cout << res;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")