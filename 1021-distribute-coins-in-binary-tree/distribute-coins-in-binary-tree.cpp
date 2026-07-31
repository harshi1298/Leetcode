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
    int ans=0;
    pair<int,int>solve(TreeNode* root){
        if(root==NULL)return {0,0};
        auto [l1,l2]=solve(root->left);
        auto [r1,r2]=solve(root->right);
        ans+=abs((l1+r1+1)-(l2+r2+root->val));
        return {l1+r1+1,l2+r2+root->val};
    }
public:
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};