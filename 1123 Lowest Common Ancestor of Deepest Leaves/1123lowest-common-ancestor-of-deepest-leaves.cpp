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
    unordered_map<TreeNode*,int>mapp;
    unordered_map<TreeNode*,TreeNode*>par;
    void dfs(TreeNode* root,int h){
        mapp[root]=h;
        if(root->left){
            par[root->left]=root;
            dfs(root->left,h+1);
        }
        if(root->right){
            dfs(root->right,h+1);
            par[root->right]=root;
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root,0);
        int maxi=0;
        for(auto[key,val]: mapp){
            maxi=max(maxi,val);
        }
        queue<TreeNode*>que;
        for(auto[key,val]: mapp){
            if(val==maxi){
                que.push(key);
            }
        }
        unordered_set<TreeNode*>vis;
        while(que.size()>1){
             int k=que.size();
             for(int i=0;i<k;i++){
                auto it=que.front();
                que.pop();
                if(vis.find(par[it])==vis.end()){
                    vis.insert(par[it]);
                    que.push(par[it]);
                }
             }
        }
        return que.front();
    }
};