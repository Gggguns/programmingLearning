#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
class Solution {
public:
    string tree2str(TreeNode* root)
    {

        string S;
        if (root == NULL)
        {
            return S;
        }
        S += to_string(root->val);
        if (root->left || root->right)
        {
            S += '(';
        }
        S += tree2str(root->left);
        if (root->left || root->right)
        {
            S += ')';
        }
        if (root->right)
        {
            S += '(';
        }
        S += tree2str(root->right);
        if (root->right)
        {
            S += ')';
        }
        return S;
    }
};
int main()
{ 

	return 0;
}