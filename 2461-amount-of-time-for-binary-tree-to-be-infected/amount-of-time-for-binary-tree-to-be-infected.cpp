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
    unordered_map<TreeNode*, vector<TreeNode*>> hm;
    queue<TreeNode*> q;
    unordered_set<TreeNode*> visited;
    void createGraph(TreeNode* root, TreeNode* parent, int& start) {
        if (root==nullptr) {
            return;
        }
        if (parent) {
            hm[root].push_back(parent);
        }
        if (root->left) {
            hm[root].push_back(root->left);
        }
        if (root->right) {
            hm[root].push_back(root->right);
        }
        if (root->val == start) {
            q.push(root);
            visited.insert(root);
        }
        createGraph(root->left, root, start);
        createGraph(root->right, root, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        createGraph(root,nullptr, start);
        int val = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0 ; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                for (int j = 0 ; j < hm[curr].size() ; j++) {
                    if (visited.count(hm[curr][j]) > 0) {
                        continue;
                    } else {
                        q.push(hm[curr][j]);
                        visited.insert(hm[curr][j]);
                    }
                }
            }
            val++;
        }
        return val;
    }

};