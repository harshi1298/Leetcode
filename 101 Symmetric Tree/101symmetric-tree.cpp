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
    bool solve(TreeNode* leftnode,TreeNode* rightnode){
        if(leftnode==NULL && rightnode==NULL)return true;
        if(!leftnode)return false;
        if(!rightnode)return false;
        if(leftnode->val==rightnode->val){
            return solve(leftnode->left,rightnode->right) && solve(leftnode->right,rightnode->left);
        }
        else{
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};