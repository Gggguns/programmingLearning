#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = -1, right = 0, size = fruits.size();
        unordered_map<int, int> hash;
        int maxSize = 0;
        while (right < size)
        {
            if (hash.count(fruits[right]) == 0 && hash.size() == 2)
            {
                maxSize = max(maxSize, right - left - 1);
                while (hash.size() == 2)
                {
                    left++;
                    int key = fruits[left];
                    hash[key]--;
                    if (hash[key] == 0)hash.erase(key);
                }
            }
            else
            {
                hash[fruits[right]]++;
                right++;
            }
        }
        maxSize = max(maxSize, right - left - 1);
        return maxSize;
    }
};
int main()
{
    return 0;
}