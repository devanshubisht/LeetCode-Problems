class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long left, long right) {
        if (!root){
            return true;
        }
        int value = root->val;
        if ((value >= right) || (left >= value)) {
            return false;
        }
        return dfs(root->right, value, right) && dfs(root->left, left, value);
    }
};