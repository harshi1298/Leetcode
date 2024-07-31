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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
         if(root==NULL) return ans;
        queue<TreeNode*> q;
        int flag=1;
        q.push(root);
        while(!q.empty()){
         vector<int>ans1;
          int k=q.size();
          if(flag){
            for(int i=0;i<k;i++){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            ans1.push_back(temp->val);
          }
          flag=0;}
          else {
             for(int i=0;i<k;i++){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            ans1.insert(ans1.begin(),temp->val);
          }
          flag=1;
          }
          ans.push_back(ans1);
        }
        return ans;
    }
};