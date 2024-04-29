#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    string str, Res = "yes";
    int n = 0;
    cin >> n >> str;
    bool flag = true, warm = false;
    unordered_map<char, int> hash;
    //统计字符数量
    for (int i = 0;i < n;i++) {
        hash[str[i]]++;
    }
    //模拟插入
    str.clear();
    while (hash.size()) {
        flag = true;
        warm = false;
        for (auto& e : hash) {
            if (str == "") {
                str += e.first;
                e.second--;
                if (e.second == 0) {
                    hash.erase(e.first);
                    flag = false;
                    break;
                }
            }
            for (size_t i = 0;i < str.size();i++) {
                if ((i == 0 && str[i] != e.first) || (str[i] != e.first && str[i - 1] != e.first)) {
                    str.insert(str.begin() + i, e.first);
                    e.second--;
                    flag = false;
                }
                else if (i == (str.size() - 1) && str[i] != e.first) {
                    str += e.first;
                    e.second--;
                    flag = false;
                }
                if (e.second == 0) {
                    hash.erase(e.first);
                    warm = true;
                    break;
                }
            }
            if (warm)break;
        }
        if (flag) {
            Res = "no";
            break;
        }
    }
    if (Res == "no")cout << Res;
    else {
        cout << Res << endl << str;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")