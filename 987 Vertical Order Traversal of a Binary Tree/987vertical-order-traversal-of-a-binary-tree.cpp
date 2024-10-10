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
   void print(vector<int>nums){
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<"  ";
    cout<<endl;
   }
    map<int,vector<int>>m;
   void solve(TreeNode *root,int fill){
     queue<pair<TreeNode*,int>>q;
     q.push({root,0});
     while(!q.empty()){
       unordered_map<int,vector<int>>tmap;
       int size=q.size();
       for(int i=0;i<size;i++){
          int fill=q.front().second;
          TreeNode*temp=q.front().first;
          q.pop();
          tmap[fill].push_back(temp->val);
          if(temp->left)q.push({temp->left,fill-1});
          if(temp->right)q.push({temp->right,fill+1});
       }
       for(auto &i: tmap){
        sort(i.second.begin(),i.second.end());
       }
       for(auto i:tmap){
        m[i.first].insert(m[i.first].end(), i.second.begin(), i.second.end());
       }
     }
   }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0);
        vector<vector<int>> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};