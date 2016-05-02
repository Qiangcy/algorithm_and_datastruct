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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            travel(root, 1, res);
            return res;
        }

        void travel(TreeNode* node, int level, vector<vector<int>> &res) {
            if(!node)
                return;
            if(level > res.size())
                res.push_back(vector<int>());
            res[level-1].push_back(node->val);
            travel(node->left,  level+1, res);
            travel(node->right, level+1, res);
        }

};
