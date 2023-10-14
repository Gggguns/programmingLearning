#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        int size1 = i - j + 1;
        int size2 = 0;
        int h = 0;
        for (h = 0;h < sizeof(int) * 8;h++)
        {
            if (m & (1 << h))
            {
                size2 = h;
            }
        }
        for (h = j;h <= i;h++)
        {
            if (n & (1 << h))
            {
                return n;
            }
        }
        if (size2 <= size1)
        {
            n |= (m << j);
        }
        return n;
    }
};
int main()
{
    int m = 0, n = 0, j = 0, i = 0;
    cin >> m >> n >> j >> i;
    BinInsert b;
    cout << b.binInsert(m, n, j, i);
    return 0;
}