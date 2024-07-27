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
    int height(TreeNode* root,int &flag){
    if(root==NULL) return 0;
    int left_h=1+height(root->left,flag);
    int right_h=1+height(root->right,flag);
    if(abs(left_h-right_h)>1) flag=0;
    if(left_h>right_h)return left_h;
    else return right_h;}
public:
    bool isBalanced(TreeNode* root) {
        int flag=1;
        height(root,flag);
        return flag;
    }
};
// class Solution {
// private:
//     int height(TreeNode* root, int &flag) {
//         if (root == NULL) return 0;
//         int left_h = height(root->left, flag);
//         int right_h = height(root->right, flag);
//         if (abs(left_h - right_h) > 1) flag = 0;
//         return 1 + max(left_h, right_h);
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         int flag = 1;
//         height(root, flag);
//         return flag == 1;
//     }
// };
