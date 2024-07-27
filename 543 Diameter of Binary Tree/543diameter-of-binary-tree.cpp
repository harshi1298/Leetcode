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
  int height(TreeNode* root,int &ans){
    if(root==NULL) return 0;
    int left_h=height(root->left,ans);
    int right_h=height(root->right,ans);
    ans=max(ans,left_h+right_h);
    return 1+max(left_h,right_h);
   }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        height(root,ans);
        return ans;
    }
};