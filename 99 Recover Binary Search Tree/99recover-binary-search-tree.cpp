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
    pair<long long,long long > solve(TreeNode* root,long long maxi,long long mini,pair<long long,long long >&a){
         if(root==NULL){
            return a;
         }
         if(root->val<maxi && root->val>mini){
            a=solve(root->left,root->val,mini,a);
            if(a.first==LLONG_MAX ){
                a=solve(root->right,maxi,root->val,a);
            }
            if(a.second==root->val){
               root->val=a.first;
               a={LLONG_MAX,LLONG_MIN};
               solve(root,maxi,mini,a);
            }
            return a;
         }
         else{
           if(root->val>maxi){
              a.first=root->val;
              a.second=maxi;
             root->val=maxi;
             return a;
                }
         else{
           a.first=root->val;
           a.second=mini;
            root->val=mini;
            return a;
         }
       }
    }
public:
    void recoverTree(TreeNode* root) {
        pair<long long,long long >a;
        a={LLONG_MAX,LLONG_MIN};
        solve(root,LLONG_MAX,LLONG_MIN,a);    }
};