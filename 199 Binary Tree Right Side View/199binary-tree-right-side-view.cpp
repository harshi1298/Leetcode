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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            vector<int> level;
            for(int i=0;i<k;i++){
                TreeNode* temp=q.front();
                q.pop();
                level.push_back(temp->val);
               if(temp->left!=NULL)q.push(temp->left);
               if(temp->right!=NULL)q.push(temp->right);
            }
            levels.push_back(level);}
        for(int i=0;i<levels.size();i++){
            int k=levels[i].size();
            ans.push_back(levels[i][k-1]);
        }
        return ans;
    }
};