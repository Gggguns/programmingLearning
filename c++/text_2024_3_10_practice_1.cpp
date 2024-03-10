#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int size = 10;
        vector<int> v1(size);
        auto v2 = v1;
        int Bulls = 0;
        for (int i = 0;i < n;i++)
        {
            if (secret[i] == guess[i])Bulls++;
            v1[secret[i] - '0']++;
            v2[guess[i] - '0']++;
        }
        int Cows = 0;
        for (int i = 0;i < size;i++)
        {
            Cows += min(v1[i], v2[i]);
        }
        Cows -= Bulls;
        string str;
        str = to_string(Bulls) + 'A' + to_string(Cows) + 'B';
        return str;
    }
};
int main()
{
    return 0;
}