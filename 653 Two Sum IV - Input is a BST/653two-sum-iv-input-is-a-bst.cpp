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
    void solve(TreeNode *root,int k,unordered_map<int,int>&mapp,int &flag){
        if(flag || root==NULL)return ;
        if(!mapp[root->val]){
       if(root->val!=k-root->val )
        mapp[k-root->val]=1;
        solve(root->left,k,mapp,flag);
        solve(root->right,k,mapp,flag);}
        else flag=1;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mapp;
        int flag=0;
        solve(root,k,mapp,flag);
        return flag;
    }
};