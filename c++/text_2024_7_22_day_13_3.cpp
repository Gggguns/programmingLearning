#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;
long long n = 0;
string str, res;
unordered_map<char, int> Hash;
long long FindPos(char ch) {
    long long size = res.size();
    if (size < 2)return -1;
    long long i = 0;
    if (res[i] != ch)return 0;
    for (i = 1;i < size;i++) {
        if (res[i] != ch && res[i - 1] != ch)return i;
    }
    return -1;
}
int main() {
    cin >> n >> str;
    bool flag = true;
    for (auto& e : str)Hash[e]++;
    if (Hash.size() == 1 && Hash[str[0]] > 1)flag = false;
    else {
        while (Hash.size()) {
            for (auto& pair : Hash) {
                char ch = pair.first;
                if (res.size()==0 || res.back() != ch) {
                    res.push_back(ch);
                    Hash[ch]--;
                    if (Hash[ch] == 0) {
                        Hash.erase(ch);
                        break;
                    }
                    continue;
                }
                else {
                    long long ret = FindPos(ch);
                    if (ret == -1) {
                        flag = false;
                        break;
                    }
                    else {
                        res.insert(ret + res.begin(), ch);
                        Hash[ch]--;
                        if (Hash[ch] == 0) {
                            Hash.erase(ch);
                            break;
                        }
                    }
                }
            }
            if (!flag)break;
        }
    }
    if (flag) {
        cout << "yes\n";
        cout << res;
    }
    else cout << "no";
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")