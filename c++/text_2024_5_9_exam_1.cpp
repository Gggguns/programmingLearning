#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    int prev = 0, post = 0, diff = 0, lenA = A.size(), lenB = B.size(), Max = 0;
    diff = abs(lenA - lenB);
    for (int i = 0;i <= diff;i++) {
        int Sum = 0, ai = 0, bi = i;
        for (;ai < lenA;ai++, bi++) {
            if (A[ai] == B[bi])Sum++;
        }
        Max = max(Max, Sum);
    }
    int Res = lenB - diff - Max;
    cout << Res;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")