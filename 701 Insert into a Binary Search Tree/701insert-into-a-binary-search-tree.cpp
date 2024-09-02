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
   TreeNode* solve(TreeNode *root,int val){
    if(root==NULL){
        TreeNode* temp=new TreeNode;
        temp->left=NULL;
        temp->right=NULL;
        temp->val=val;
        return temp;
        }
     if(val<root->val){
        root->left=solve(root->left,val);
     }
     else root->right=solve(root->right,val);
     return root;
   }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root,val);
       
    }
};