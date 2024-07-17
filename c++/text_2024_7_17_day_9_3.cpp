#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool IsContinuous(vector<int>& numbers) {
        int countZero = 0, minNum = 100, index = 0;
        sort(numbers.begin(), numbers.end());
        int size = numbers.size();
        for (int i = 0;i < size;i++) {
            if (numbers[i] == 0)countZero++;
            else if (numbers[i] < minNum) {
                minNum = numbers[i];
                index = i + 1;
                break;
            }
        }
        for (int i = index;i < size;) {
            if (numbers[i] - 1 == minNum) {
                minNum++;
                i++;
            }
            else if (numbers[i] > minNum) {
                minNum++;
                countZero--;
                if (countZero < 0)return false;
            }
            else return false;
        }
        if (minNum == numbers.back())return true;
        else return false;
    }
};
int main() {
    vector<int> numbers = { 6,0,2,0,4 };
    Solution s;
    s.IsContinuous(numbers);
    return 0;
}