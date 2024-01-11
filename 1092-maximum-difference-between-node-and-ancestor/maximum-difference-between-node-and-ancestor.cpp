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
    int result = INT_MIN;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MIN, INT_MAX);
        return result;
    }
    void dfs(TreeNode* root, int max, int min) {
        if (!root) {
            return;
        }
        int newMin = std::min(min, root->val);
        int newMax = std::max(max, root->val);
        result = std::max(result, abs(newMax - newMin));
        dfs(root->left, newMax, newMin);
        dfs(root->right, newMax, newMin);
    }
};