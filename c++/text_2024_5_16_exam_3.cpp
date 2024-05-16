#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
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
    long long prevOrder(TreeNode* root) {
        if (root == nullptr)return 0;
        long long left = prevOrder(root->left);
        long long right = prevOrder(root->right);
        Max = max(Max, left + right + root->val);
        long long Res = max(left, right);
        if (Res < 0)return root->val;
        else return Res + root->val;
    }
    int maxPathSum(TreeNode* root) {
        Max = max(Max, prevOrder(root));
        return Max;
    }
    long long Max = -0x3fffff;
};
int main() {
    return 0;
}