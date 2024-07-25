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
   void solve(TreeNode* root, int sum,vector<int> ans1,vector<vector<int>> &ans,int sum2){
    if(root==NULL){
        return;
    }
    sum2=sum2+root->val;
     ans1.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
            if (sum2 == sum) {
                ans.push_back(ans1);
            }
    }
    solve(root->left,sum,ans1,ans,sum2);
    solve(root->right,sum,ans1,ans,sum2);
     ans1.pop_back();
   }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans1;
        vector<vector<int>> ans;
        solve(root,targetSum,ans1,ans,0);
        return ans;
    }
};