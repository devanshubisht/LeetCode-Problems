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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }

        vector<int> res;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int currentLength = queue.size();
            int currMax = INT_MIN;

            while (currentLength > 0) {
                TreeNode* curr = queue.front();
                queue.pop();
                currMax = max(currMax, curr->val);

                if (curr->left) {
                    queue.push(curr->left);
                }
                if (curr->right) {
                    queue.push(curr->right);
                }
                currentLength -= 1;
            }

            res.push_back(currMax);
        }
        return res;
    }
};