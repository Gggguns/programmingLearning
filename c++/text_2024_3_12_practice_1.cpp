#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
 struct TreeNode 
 {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class FindElements {
public:
    FindElements(TreeNode* root) {
        _root = root;
        queue<TreeNode*> q;
        if (root)
        {
            root->val = 0;
            q.push(root);
        }
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left)
            {
                q.push(cur->left);
                cur->left->val = 2 * cur->val + 1;
            }
            if (cur->right)
            {
                q.push(cur->right);
                cur->right->val = 2 * cur->val + 2;
            }
        }
    }

    bool find(int target)
    {
        queue<TreeNode*> q;
        if (_root)
        {
            if (_root->val == target)return true;
            q.push(_root);
        }
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->val == target)return true;
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }
        return false;
    }
    TreeNode* _root;
};

int main()
{
	
	return 0;
}