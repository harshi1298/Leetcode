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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        while( !q.empty()){
            int k=q.size();
            vector<int>ans1;
            for(int i=0;i<k;i++){
            TreeNode* temp=q.front();
            ans1.push_back(temp->val);
            q.pop();
           if(temp->left!=NULL){ q.push(temp->left);}
            if(temp->right!=NULL){q.push(temp->right);}}
            ans.insert(ans.begin(),ans1);
        }
        return ans;
    }
};