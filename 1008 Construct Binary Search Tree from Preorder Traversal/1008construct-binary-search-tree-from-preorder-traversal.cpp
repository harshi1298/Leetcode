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
   TreeNode* solve(vector<int>arr,int &ind,int maxi){
    if(ind>=arr.size() || arr[ind]>maxi){
        return NULL;
    }
    TreeNode* temp=new TreeNode(arr[ind++]);
    temp->left=solve(arr,ind,temp->val);
    temp->right=solve(arr,ind,maxi);
    return temp;
}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
};