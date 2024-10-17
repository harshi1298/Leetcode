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
   unordered_map<int,int>inmapp;
   TreeNode* solve(vector<int>postorder,vector<int>inorder,int pos,int ins,int pod,int iod){
        if(ins>iod || pos>pod)return NULL;
        TreeNode*head=new TreeNode(postorder[pod]);
        int numsleft=inmapp[head->val]-ins;
        head->left=solve(postorder,inorder,pos,ins,pos+numsleft-1,inmapp[head->val]-1);
        head->right=solve(postorder,inorder,pod-iod+inmapp[head->val],inmapp[head->val]+1,pod-1,iod);
        return head;
   }
   
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       for(int i=0;i<inorder.size();i++)inmapp[inorder[i]]=i;
       return solve(postorder,inorder,0,0,postorder.size()-1,inorder.size()-1);
    }
};