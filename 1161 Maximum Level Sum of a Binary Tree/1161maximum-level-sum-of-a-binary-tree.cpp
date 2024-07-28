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
    int maxLevelSum(TreeNode* root) {
          vector<int> ans;
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            int sum=0;
            for(int i=0;i<k;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum=sum+temp->val;
               if(temp->left!=NULL)q.push(temp->left);
               if(temp->right!=NULL)q.push(temp->right);
            }
            ans.push_back(sum);}
        int max=-(1e5-1);
        int max_level=0;
        for(int i=0;i<ans.size();i++){
            if(max<ans[i]) {max=ans[i]; max_level=i;}
        }
        return max_level+1;
    }
};