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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;
        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                st.push(root);
                root = root->left; 
            }
            TreeNode* topNode = st.top(); 
            if (topNode->right == nullptr || topNode->right == lastVisited) {
                ans.push_back(topNode->val); 
                st.pop();  
                lastVisited = topNode;  
            } else {
                root = topNode->right; 
            }
        }
        return ans;
    }
};
