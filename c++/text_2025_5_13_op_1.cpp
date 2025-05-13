#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string str = "croak";
        int n = str.size();
        vector<int> hash(n);
        unordered_map<char, int> index;
        for (int i = 0; i < n; i++)
        {
            index[str[i]] = i;
        }
        int ret = 0;
        for (auto e : croakOfFrogs)
        {
            if (e == 'c')
            {
                if (hash[index['k']])
                {
                    hash[index['k']]--;
                }
                else
                {
                    ret++;
                }
                hash[index['c']]++;
            }
            else
            {
                hash[index[e] - 1]--;
                if (hash[index[e] - 1] < 0)return -1;
                hash[index[e]]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
            if (hash[i])return -1;
        return ret;
    }
};
int main()
{
    return 0;
}