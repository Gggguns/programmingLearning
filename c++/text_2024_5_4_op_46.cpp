#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        srand(time(NULL));
        qsort(stock, 0, stock.size() - 1, cnt);
        vector<int> Ret;
        return { stock.begin(),stock.begin() + cnt };
    }
    int getRoman(int left, int right) {
        int Rom = rand();
        return (Rom % (right - left + 1) + left);
    }
    void qsort(vector<int>& stock, int left, int right, int k) {
        if (left >= right || k == 0)return;
        int begin = left, end = right;
        int key = stock[getRoman(left, right)];
        int cur = left;
        left -= 1;
        right += 1;
        while (cur < right) {
            if (stock[cur] < key)swap(stock[++left], stock[cur++]);
            else if (stock[cur] == key)cur++;
            else swap(stock[cur], stock[--right]);
        }
        int a = left - begin + 1;
        int b = cur - left - 1;
        if (a > k)qsort(stock, begin, left, k);
        else if (a + b >= k)return;
        else qsort(stock, right, end, k - a - b);
    }
};
int main() {
    Solution s;
    vector<int> stock = { 0,0,1,3,4,5,0,7,6,7 };
    vector<int> Ret=s.inventoryManagement(stock, 9);
    for (auto e : Ret)cout << e << ' ';
    return 0;
}