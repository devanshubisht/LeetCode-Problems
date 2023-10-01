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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int result = 0;
        int left=0;
        int right=0;
        while (!q.empty()) {
            int size = q.size();
            for(int i = 0 ; i < size ; i++) {
                pair<TreeNode*, long long int> value = q.front();
                q.pop();
                if (i == 0) {
                   left = value.second; 
                }
                if (i == size -1) {
                    right = value.second;
                }
                if (value.first->left) {
                    q.push({value.first->left,2 *value.second+1});
                }
                if (value.first->right) {
                    q.push({value.first->right, 2*value.second +2});
                }
            }
            result = max(result, abs(right - left + 1));
        }
        return result;
    }
};