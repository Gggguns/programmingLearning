#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
bool Top(vector<int>& ST) {
    if (ST.empty()) {
        cout << "error" << endl;
        return false;
    }
    cout << ST.back() << endl;
    return true;
}

int main() {
    vector<int> ST;
    long n = 0;
    cin >> n;
    while (n--)
    {
        string op;
        int num = 0;
        cin >> op;
        if (op == "push")
        {
            cin >> num;
            ST.push_back(num);
        }
        else if (op == "pop") {
            if (Top(ST) == false)continue;
            ST.pop_back();
        }
        else if (op == "top")Top(ST);
    }
    return 0;
}
