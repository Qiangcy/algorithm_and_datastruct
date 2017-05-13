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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return 1;
        if(root->left==nullptr && root->right==nullptr) {
            return 1;
        }else if(root->left && root->right==nullptr) {
            return root->left->val < root->val;
        }else if(root->right && root->left==nullptr) {
            return root->right->val > root->val;
        }else {
             return root->left->val  < root->val
                 && root->right->val > root->val
                 && isValidBST(root->left)
                 && isValidBST(root->right);
        }
    }
};
