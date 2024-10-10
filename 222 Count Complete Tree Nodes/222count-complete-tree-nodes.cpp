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
    int ans=0;
private:
  void solve(TreeNode *root){
    if(root==NULL){
        return ;
    }
    else if(root->left==NULL && root->right==NULL)return;
    else if(!root->left || !root->right){
        ans++;
        return;
    }
    else{
        ans=ans+2;
        solve(root->left);
        solve(root->right);
    }
  }

public:
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        solve(root);
        return ans+1;
    }
};