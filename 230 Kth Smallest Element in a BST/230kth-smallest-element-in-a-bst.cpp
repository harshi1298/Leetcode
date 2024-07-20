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
  void smallest(TreeNode* root, int &k,int &ans){
    cout<<k<<endl;
    if(root==NULL) {
       return;}
        smallest(root->left,k,ans);
        k--;
     if(k==0){
        ans=root->val;
        return;
    }
        smallest(root->right,k,ans);
}

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int l=k;
        smallest(root,l,ans);
        return ans;
    }
};