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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>mapp;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            auto k=que.front();
            que.pop();
            if(k->left){
                mapp[k->val].push_back(k->left->val);
                mapp[k->left->val].push_back(k->val);
                que.push(k->left);
            }
            if(k->right){
                mapp[k->val].push_back(k->right->val);
                mapp[k->right->val].push_back(k->val);
                que.push(k->right);
            }
        }
        int ans=-1;
        queue<int>qu;
         unordered_set<int> vis;
         vis.insert(start);
        qu.push(start);
        while(!qu.empty()){
            ans++;
            int size=qu.size();
            for(int i=0;i<size;i++){
                int from=qu.front();
                qu.pop();
                for(auto it :mapp[from]){
                    if(vis.find(it)==vis.end()){
                        vis.insert(it);
                        qu.push(it);
                    }
                }
            }
        }
        return ans;
    }
};