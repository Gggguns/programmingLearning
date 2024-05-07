#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<string> v(n);
        for (int i = 0;i < n;i++)cin >> v[i];
        int left = 0, right = n - 1;
        bool flag = false;
        while (left < right) {
            flag = false;
            for (auto e : v[left]) {
                if (v[right].find(e) != string::npos)flag = true;
                if (flag)break;
            }
            if (flag == false)break;
            left++;
            right--;
        }
        if (flag)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
// 64 位输出请用 printf("%lld")

// 64 位输出请用 printf("%lld")
