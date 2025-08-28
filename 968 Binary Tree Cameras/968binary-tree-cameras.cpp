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
    vector<int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0,99999};
        }
        vector<int>left=solve(root->left);
        vector<int>right=solve(root->right);
        int  p1=min(left[1],left[2]);
        int p2=min(right[1],right[2]);
        int q0=p1+p2;
        int q1=min(p1+right[2],p2+left[2]);
        int q2=1+min(left[0],p1)+min(right[0],p2);
        return {q0,q1,q2};
    }
public:
    int minCameraCover(TreeNode* root) {
        vector<int>temp=solve(root);
        return min(temp[1],temp[2]);
    }
};