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
    int ans=INT_MIN;
   int solve(TreeNode* hello){
    if(hello==NULL) return 0;
    int left=solve(hello->left);
    int right=solve(hello->right);
    ans=max(ans,hello->val);
    ans=max(ans,hello->val+left);
    ans=max(ans,hello->val+right);
    ans=max(ans,left+hello->val+right);
    return max(hello->val, hello->val+max(left,right));
   }
public:
    int maxPathSum(TreeNode* hello) {
       solve(hello);
       return ans;
    }
};