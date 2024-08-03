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
     vector<TreeNode*> f(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(NULL); // Base case: empty subtree
            return result;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubtrees = f(start, i - 1);
            vector<TreeNode*> rightSubtrees = f(i + 1, end);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return f(1, n);
    }
};