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
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> hm;
        dfs(root, hm);
        return result;
    }

    void dfs(TreeNode* root, unordered_map<int,int>& hm) {
        hm[root->val]+=1;
        if (root->left==nullptr && root->right == nullptr) {
            int count = 0;
            for (auto const& pairs : hm) {
                if (pairs.second % 2 != 0) {
                    count++;
                }
            }
            if (count <= 1) {
                result+=1;
            }
            hm[root->val]-=1;
            return;
        }
        if (root->left) {
            dfs(root->left, hm);
        }
        if (root->right) {
            dfs(root->right, hm);
        }
        hm[root->val]-=1;
    }
};
