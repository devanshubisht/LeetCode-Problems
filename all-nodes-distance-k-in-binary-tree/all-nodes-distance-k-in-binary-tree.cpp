/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0 ; i < size; i++) {
                auto top = q.front();
                q.pop();
                if (top-> left) {
                    parent[top->left] = top;
                    q.push(top->left);
                }
                if (top-> right) {
                    parent[top->right] = top;
                    q.push(top->right);
                }
            }
        }

        vector<int> result;
        q.push(target);
        unordered_map<int, int> visited;
        while(!q.empty() && k>0 ) {
            int size = q.size();
            for(int i = 0 ; i < size; i++) {
                auto top = q.front();
                q.pop();
                visited[top->val] = 1;
                if(top -> left && !visited[top->left->val]){
                    q.push(top -> left);
                }

                if(top -> right && !visited[top->right->val]){
                    q.push(top -> right);
                }

                if(parent[top] && !visited[parent[top]->val]){
                    q.push(parent[top]);
                }
            }
            k--;
        }

        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;

    }
};