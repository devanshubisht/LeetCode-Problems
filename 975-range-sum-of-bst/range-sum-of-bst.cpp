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
    int result = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return result;
        }
        if (low <= root->val && root->val <= high) {
            result += root->val;
        }
        if (root->val < high) {
            rangeSumBST(root->right, low, high);
        }
        if (root->val > low) {
            rangeSumBST(root->left, low, high);
        }
        return result;
    }
};