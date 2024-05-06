#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:

    int knapsack(int V, int n, vector<vector<int> >& vw) {
        unordered_map<int, int> hash;
        //≥ı ºªØ
        for (int i = vw[0][0];i <= V;i++)hash[i] = vw[0][1];
        for (int i = 1;i < n;i++) {
            int curv = vw[i][0];
            int curw = vw[i][1];
            for (int j = V;j >= curv;j--) {
                if (hash[j - curv] + curw > hash[j])hash[j] = hash[j - curv] + curw;
            }
        }
        int Max = 0;
        for (auto& e : hash) {
            if (e.second > Max)Max = e.second;
        }
        return Max;
    }
};
int main() {
	return 0;
}