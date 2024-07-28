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
  TreeNode* searchbst(TreeNode* root, int val) {
        if(root==NULL||root->val==val)
         return root;
        if(root->val>val)return searchbst(root->left,val);
        else return searchbst(root->right,val);

    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchbst(root,val);
    }
};