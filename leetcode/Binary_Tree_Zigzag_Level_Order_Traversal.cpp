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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        travel(root, 1, res);
        for(int i=1; i<res.size(); i+=2) {
            reverse(begin(res[i]), end(res[i]));
        }
        return res;
    }

    void travel(TreeNode * root, int level, vector<vector<int>> &res) {
        if(!root)
            return;
        if(level > res.size())
            res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        travel(root->left,  level+1, res);
        travel(root->right, level+1, res);
    }
};
