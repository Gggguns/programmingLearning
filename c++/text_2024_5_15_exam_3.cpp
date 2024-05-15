#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        sort(startEnd.begin(), startEnd.end());
        priority_queue<int,vector<int>,greater<int>> Q;
        for (auto e : startEnd) {
            if (Q.size() == 0) {
                Q.push(e[1]);
            }
            else {
                if (e[0] >= Q.top()) {
                    Q.pop();
                    Q.push(e[1]);
                }
                else Q.push(e[1]);
            }
        }
        return Q.size();
    }
};
int main() {
    Solution s;
    vector<vector<int> > startEnd = { {2,3},{1,2},{1,3},{2,5} };
    s.minmumNumberOfHost(2,startEnd);
	return 0;
}