#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int Count = 0;
size_t sz = 0;
vector<pair<int,bool>> v;
void div(int num) {
    v.clear();
    while (num) {
        if (num % 10 != 0)v.push_back({num%10,false});
        num /= 10;
    }
}
//判质数
bool isPrime(int num) {
    if (num == 1)return false;
    if (num == 2)return true;
    for (int i = 2;i <= sqrt(num);i++) {
        if (num % i == 0)return false;
    }
    return true;
}
//深搜
bool dfs(int num, int level, int k) {
    num = num * 10 + v[k].first;
    level++;
    if (level == 2)return isPrime(num);
    bool flag = false;
    v[k].second = true;
    for (size_t j = 0;j < sz;j++)
        if (!v[j].second && dfs(num, level, j)) {
            flag = true;
            break;
        }
    v[k].second = false;
    return flag;
}
int main() {
    int a = 0, b = 0;
    cin >> a >> b;
    for (int i = a;i <= b;i++) {
        div(i);
        sz = v.size();
        for (size_t k = 0;k < sz;k++)
            if (dfs(0, 0, k)) {
                Count++;
                break;
            }
    }
    cout << Count;
    return 0;
}
// 64 位输出请用 printf("%lld")