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
   void istrue(TreeNode* p, TreeNode* q,int &flag){
    if(p==NULL && q==NULL) return ;
    if(flag==0) return ;
    if((p==NULL)^(q==NULL)){
        flag=0;
        return;
    }
    if(p->val==q->val) {
        istrue(p->left,q->left,flag);
        istrue(p->right,q->right,flag);
          }
    else{
        flag=0;
        return ;
    }
  
   }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int flag=1;
        istrue(p,q,flag);
        return flag;
    }
};