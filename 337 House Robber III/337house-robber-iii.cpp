/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    pair<int,int>solve(TreeNode* root){
        if(root==NULL)return {0,0};
        auto [l1,l2]=solve(root->left);
        auto [r1,r2]=solve(root->right);
        int m1=root->val+l2+r2;
        int m2=max(l1,l2)+max(r1,r2);
        return {m1,m2};
    }
public:
    int rob(TreeNode* root) {
        auto [l,r]=solve(root);
        return max(l,r);
    }
};