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
   bool solve(TreeNode* root,long long mini,long long maxi){
    if(root==NULL)return true;
    if(root->val<mini &&  root->val>maxi){
        return solve(root->right,mini,root->val) && solve(root->left,root->val,maxi);
    }
    else return false;
   }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MAX,LLONG_MIN);
    }
};