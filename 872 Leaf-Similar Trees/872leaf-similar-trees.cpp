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
   void findleaf(TreeNode* root,vector<int> &ans){
    if(root==NULL) return ;
    if(root->left==NULL &&root->right==NULL){
        ans.push_back(root->val);
        return;
    }
    if(root->left!=NULL)findleaf(root->left,ans);
    if(root->right!=NULL)findleaf(root->right,ans);
   }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1,ans2;
        findleaf(root1,ans1);
        findleaf(root2,ans2);
        if(ans1.size()!=ans2.size()) return 0;
        bool flag=1;
        for(int i=0;i<ans1.size();i++) if(ans1[i]!=ans2[i]) return 0;
        return 1;
    }
};