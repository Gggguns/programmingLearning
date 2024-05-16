#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<bool> vis;
vector<int> nums;
int Count = 0, n = 0;
void dfs(int index, int k) {
    if (vis[nums[index]] == true)return;
    if (k == n)Count++;
    vis[index] = true;
    for (int i = 1;i <= n;i++) {
        if (vis[i] == false)dfs(i, k + 1);
    }
    vis[index] = false;
}
int main() {
    cin >> n;
    vis.resize(n + 1);
    nums.resize(n + 1);
    for (int i = 1;i <= n;i++)cin >> nums[i];
    for (int i = 1;i <= n;i++) {
        dfs(i, 1);
    }
    cout << Count;
    return 0;
}