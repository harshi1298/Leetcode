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
   void solve(TreeNode* root){
    if(root==NULL)return;
    stack<TreeNode*>st;
    TreeNode *temp=root;
    while(temp){
        if(temp->right){
        st.push(temp->right);
        }
        temp->right=temp->left;
        temp->left=NULL;
        if(temp->right==NULL && !st.empty()){
            temp->right=st.top();
            st.pop();
        }
        temp=temp->right;
   }
}
public:
    void flatten(TreeNode* root) {
        TreeNode*temp=NULL;
        if(root==NULL)return;
        solve(root);
    }
};