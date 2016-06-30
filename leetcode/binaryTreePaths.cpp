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
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> vec;
            string res;
            travel(root, res, vec);
            return vec;
        }
    private:
        void travel(TreeNode* root, string res, vector<string> &vec) {
            if(root == nullptr)
                return;
            if((root->left==nullptr&&root->right==nullptr)) {
                res = res + to_string(root->val);
                vec.push_back(res);
                return;
            }
            res = res + to_string(root->val) + "->" ;
            travel(root->left, res, vec);
            travel(root->right,res, vec);
        }
};
