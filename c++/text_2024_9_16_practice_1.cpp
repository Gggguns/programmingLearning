#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *_left;
    TreeNode *_right;
    TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), _left(left), _right(right) {}
 };
 


//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        int x = 0;
//        PostOrder(root, p, res1);
//        PostOrder(root, q, res2);
//        size_t i = 0;
//        for (i = 0;i < res1.size() && i < res2.size();i++) {
//            if (res1[i] != res2[i]) {
//                break;
//            }
//        }
//        if (i == 0)return nullptr;
//        else {
//            return res1[i - 1];
//        }
//    }
//
//    bool PostOrder(TreeNode* root, TreeNode* des, vector<TreeNode*>& res) {
//        if (root == nullptr)return false;
//        if (root == des) {
//            res.push_back(des);
//            return true;
//        }
//        TreeNode* Left = root->_left;
//        TreeNode* Right = root->_right;
//        if (Left && PostOrder(Left, des, res)) {
//            res.push_back(root);
//            return true;
//        }
//        if (Right && PostOrder(Right, des, res)) {
//            res.push_back(root);
//            return true;
//        }
//        return false;
//    }
//    vector<TreeNode*> res1;
//    vector<TreeNode*> res2;
//};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)return false;
        bool lson = dfs(root->_left, p, q);
        bool rson = dfs(root->_right, p, q);
        if (lson && rson || ((root == p || root == q) && (lson || rson))) {
            ans = root;
        }
        return lson || rson || (root == p || root == q);
    }
    TreeNode* ans = nullptr;
};
int main()
{
    TreeNode n1(4);
    TreeNode n2(7);
    TreeNode n3(8);
    TreeNode n4(0);
    TreeNode n5(2, &n2, &n1);
    TreeNode n6(6);
    TreeNode n7(1, &n4, &n3);
    TreeNode n8(5, &n6, &n5);
    TreeNode n9(3, &n8, &n7);
    Solution S;
    S.lowestCommonAncestor(&n9, &n8, &n7);
	return 0;
}