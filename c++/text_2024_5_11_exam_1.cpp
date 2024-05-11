#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    int IsBalanced(TreeNode* pRoot) {
        if (pRoot == nullptr)return 0;
        int left = IsBalanced(pRoot->left);
        int right = IsBalanced(pRoot->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)return -1;
        else return max(left, right) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int Ret = IsBalanced(pRoot);
        if (Ret == -1)return false;
        else return true;
    }
};
int main() {
	return 0;
}