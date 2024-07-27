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
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
       if(root==NULL) return ans;
       stack<TreeNode*> a;
       a.push(root);
       while(!a.empty()){ 
        TreeNode* temp=a.top();
         a.pop();
         ans.push_back(temp->val);
         if(temp->right!=NULL) a.push(temp->right);
        if(temp->left!=NULL) a.push(temp->left);
       } 
       return ans;
    }
};