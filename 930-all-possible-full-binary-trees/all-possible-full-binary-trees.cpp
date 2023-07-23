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
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        return dfs(n);
    }

    vector<TreeNode*> dfs(int n) {
        vector<TreeNode*> nodes;
        if (n == 0) {
            return nodes;
        }
        if (n == 1) {
            nodes.emplace_back(new TreeNode(0));
            return nodes;
        }

        if (dp.find(n) != dp.end()) {
            return dp[n];
        }

        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=dfs(i);
            vector<TreeNode*> right=dfs(n-i-1);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    nodes.emplace_back(root);
                }
            }  
        }
        return dp[n]= nodes;
    }
};