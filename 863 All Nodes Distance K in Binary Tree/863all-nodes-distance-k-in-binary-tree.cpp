/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int l) {
        unordered_map<TreeNode*,TreeNode*>par;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            auto k=que.front();
            que.pop();
            if(k->left){
                par[k->left]=k;
                que.push(k->left);
            }
            if(k->right){
                par[k->right]=k;
                que.push(k->right);
            }
        }
        unordered_set<TreeNode*>vis;
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        vis.insert(target);
        vector<int>ans;
        while(!q.empty()){
          auto [temp,c]=q.front();
          q.pop();
          if(c>l)continue;
          if(c==l){
            ans.push_back(temp->val);
            continue;
          }
          if(temp->left && vis.find(temp->left)==vis.end()){
            q.push({temp->left,c+1});
            vis.insert(temp->left);
          }
          if(temp->right&& vis.find(temp->right)==vis.end()){
            q.push({temp->right,c+1});
            vis.insert(temp->right);
          }
          if(par.find(temp)!=par.end() && vis.find(par[temp])==vis.end()){
            q.push({par[temp],c+1});
            vis.insert(par[temp]);
          }
        }
        return ans;
    }
};