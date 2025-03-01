#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ktime = 0;
        int size = tickets.size();
        int i = 0;
        while (i < size && tickets[k] != 0)
        {
            if (tickets[i])
            {
                tickets[i]--;
                ktime++;
            }
            i = (i + 1) % size;
        }
        return ktime;
    }
};
int main()
{
	return 0;
}