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
   TreeNode* solve(TreeNode* root, int key){
    if(root==NULL)return root;
    if(root->val==key){
          if(root->left && root->right){
            TreeNode* temp=root->right;
            while(temp->left)temp=temp->left;
            root->val=temp->val;
            root->right=solve(root->right,temp->val);
            return root;
          }
          if(root->left)return root->left;
          if(root->right)return root->right;
          else return NULL;
    }
    if(root->val>key){
        root->left=solve(root->left,key);
    }
    else root->right=solve(root->right,key);
    return root;
   }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);
    }
};