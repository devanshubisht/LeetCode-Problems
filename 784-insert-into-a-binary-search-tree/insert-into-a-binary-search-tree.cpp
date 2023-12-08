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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root) {
            dfs(root,val);
        } else {
            return new TreeNode(val);
        }
        return root;
    }

    void dfs(TreeNode* root, int val) {
        if (val <= root->val) {
            if (root->left != nullptr) {
                return dfs(root->left , val);
            } else {
                root->left = new TreeNode(val);
                return;
            }
        }
        if (val >= root->val) {
            if (root ->right != nullptr) {
                return dfs(root->right , val);
            } else {
                root->right = new TreeNode(val);
                return;
            }
        }
    }
};