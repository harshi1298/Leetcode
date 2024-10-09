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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int k=q.size();
            long long min=q.front().second;
            int left=-1,right=-1;
            for(int i=0;i<k;i++){
                TreeNode* temp=q.front().first;
                long long id=q.front().second-min;
                q.pop();
                if(i==0)left=id;
                if(i==k-1)right=id;
                if(temp->left)q.push({temp->left,2*id+1});
                if(temp->right)q.push({temp->right,2*id+2});
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};