#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cmath>
#include<unordered_map>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string str1, str2, str;
    cin >> str1 >> str2;
    unordered_map<string, int> hash;
    hash[str1] = -1;hash[str2] = -1;
    int Res = 0x3ffffff, i = 0;
    while (i < n) {
        cin >> str;
        if (hash.count(str)) {
            hash[str] = i;
            if (hash[str1] != -1 && hash[str2] != -1)
                Res = min(Res, abs(hash[str1] - hash[str2]));
        }
        i++;
    }
    if (hash[str1] == -1 || hash[str2] == -1)
        cout << -1;
    else cout << Res;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")