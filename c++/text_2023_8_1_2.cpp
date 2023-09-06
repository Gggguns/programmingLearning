#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        vector<vector<int>> vv;
        vector<int> v;
        q1.push(root);
        while (!q1.empty() || !q2.empty())
        {

            while (!q1.empty())
            {
                TreeNode* cur = q1.front();
                q1.pop();
                if (cur)
                {
                    v.push_back(cur->val);
                    q2.push(cur->left);
                    q2.push(cur->right);
                }
            }
            if (v.size())
            {
                vv.push_back(v);
                v.clear();
            }
            while (!q2.empty())
            {
                TreeNode* cur = q2.front();
                q2.pop();
                if (cur)
                {
                    v.push_back(cur->val);
                    q1.push(cur->left);
                    q1.push(cur->right);
                }
            }
            if (v.size())
            {
                vv.push_back(v);
                v.clear();
            }
        }
        return vv;
    }
};
int main()
{

    TreeNode* T1 = new TreeNode(3);
    TreeNode* T2 = new TreeNode(9);
    TreeNode* T3 = new TreeNode(20);
    TreeNode* T4 = new TreeNode(15);
    TreeNode* T5 = new TreeNode(7);
    T1->left = T2;
    T1->right = T3;
    T3->left = T4;
    T3->right = T5;
    Solution s;
    s.levelOrder(T1);
    //s.levelOrder(T1);
    
    return 0;
}