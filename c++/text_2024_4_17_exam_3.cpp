#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
using namespace std;

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    priority_queue<int, vector<int>, less<int>> p;
    long long Sum = 0;
    long long num = 0;
    while (n--) {
        cin >> num;
        Sum += num;
        if (num % 2 == 0)p.push(num);
    }
    while (k--) {
        if (!p.empty())num = p.top();
        else break;
        p.pop();
        num /= 2;
        Sum -= num;
        if (num % 2 == 0)p.push(num);
    }
    cout << Sum;
    return 0;
}