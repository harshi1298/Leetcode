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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>que;
        if(root==NULL)return root;
        que.push(root);
        int lvl=0;
        while(!que.empty()){
            int t=que.size();
            queue<TreeNode *>temp;
            stack<int>st;
            for(int i=0;i<t;i++){
                TreeNode* k=que.front();
                temp.push(k);
                st.push(k->val);
                que.pop();
                if(k->left){
                    que.push(k->left);
                }
                if(k->right){
                    que.push(k->right);
                }
            }
            while(lvl%2 && (!temp.empty())){
                TreeNode* t=temp.front();
                t->val=st.top();
                st.pop();
                temp.pop();
            }
           lvl++;
           }
        return root;
    }
};