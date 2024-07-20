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
  void getsum(TreeNode* temp,int &ans,int a){
    if(temp==NULL)return;
    a=a*10+temp->val;
    cout<<a<<endl;
    if(temp->left==NULL&&temp->right==NULL){
        ans+=a;
        return;
    }   
    getsum(temp->left,ans,a);
    getsum(temp->right,ans,a);
  }
public:
    int sumNumbers(TreeNode* root) {
        int ans=0,a=0;
        getsum(root,ans,a);
        return ans;
    }
};