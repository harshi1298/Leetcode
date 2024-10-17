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
    TreeNode* solve(vector<int> & preorder,vector<int> &inorder,int pres,int ins,int preed,int ined){
         if(ins>ined || pres>preed)return NULL;
         TreeNode* head=new TreeNode(preorder[pres]);
         head->left=solve(preorder,inorder,pres+1,ins,pres+(inmapp[head->val]-ins),inmapp[head->val]-1);
         head->right=solve(preorder,inorder,preed-(ined-inmapp[head->val])+1,inmapp[head->val]+1,preed,ined);
         return head;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)inmapp[inorder[i]]=i;
        return solve(preorder,inorder,0,0,preorder.size()-1,inorder.size()-1);
    }
};