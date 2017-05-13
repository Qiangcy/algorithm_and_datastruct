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
    bool isSymmetric(TreeNode* root) {
        vector<vector<int>> res;
        travel(root, 1, res);

        int level = 0;
        for(auto it=begin(res); it!=end(res); ++it) {
            int cut = it->size() / 2;
            if(cut!=0 && level!=0)
                return false;
            auto be = it->begin();
            auto ce = it->rbegin();
            int cnt = 0;
            for(; *be == *ce; ++be, ++ce)
                ++cnt;
            if(cnt != cut)
                return false;
            ++level;
        }
        return true;
    }


    void travel(TreeNode* root, int level, vector<vector<int>> &res )
    {
        if(!root)
            return;
        if(level > res.size())
            res.push_back(vector<int>());
        res[level-1].push_back(root->val);
        travel(root->left, left+1, res);
        travel(root->right, left+1, res);
    }
};

