#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include<string>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) { // 注意 while 处理多个 case
        for (auto& e : str)
        {
            if (e == ' ')continue;
            if (e - 'A' < 5)e = e + 21;
            else e -= 5;
        }
        cout << str << endl;
    }
}
// 64 位输出请用 printf("%lld")