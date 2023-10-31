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
    int maxVal = INT_MIN ;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxVal;
    }

    int dfs(TreeNode* curr) {
        int leftSum = 0;
        int rightSum = 0;
        if (curr->left) {
            leftSum = max(0, dfs(curr->left));
        }
        if (curr->right) {
            rightSum = max(0, dfs(curr->right));
        }
        int currSum = max(curr->val + leftSum + rightSum, curr->val);

        maxVal = max(maxVal, currSum);

        return max(curr->val + leftSum , curr->val + rightSum);
    }
};