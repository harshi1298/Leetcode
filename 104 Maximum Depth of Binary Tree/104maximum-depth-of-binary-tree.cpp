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
   int height(TreeNode* root){
    if(root==NULL) return 0;
    int left_h=1+height(root->left);
    int right_h=1+height(root->right);
    if(left_h>right_h)return left_h;
    else return right_h;
   }
public:
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};