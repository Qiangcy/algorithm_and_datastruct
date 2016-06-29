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
    bool check(TreeNode* left_node, TreeNode* right_node) {
        if(left_node==nullptr && right_node==nullptr)
            return true;
        else if(left_node==nullptr || right_node==nullptr)
            return false;
        return left_node->val==right_node->val &&
            check(left_node->left, right_node->right) &&
            check(left_node->right, right_node->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return check(root->left, root->right);
    }
};
