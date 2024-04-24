#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool IsContinuous(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        int count = 0;
        size_t i = 0;
        while (i < numbers.size()) {
            if (numbers[i] == 0) {
                count++;
                i++;
            }
            else break;
        }
        if (count == 4)return true;
        int Res = 0;
        while (i + 1 < numbers.size()) {
            Res = numbers[i + 1] - numbers[i] - 1;
            if (Res < 0)return false;
            count -= Res;
            i++;
        }
        if (count < 0)return false;
        return true;
    }
};
int main() {
    return 0;
}