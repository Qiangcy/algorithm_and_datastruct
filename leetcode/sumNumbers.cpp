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
        int sumNumbers(TreeNode* root) {
            return inorder_travesal(root, 0);
        }
    private:
        int inorder_travesal(TreeNode* root, int sum) {
            if(root == nullptr)
                return 0;
            sum = sum*10 + root->val;
            if(root->left==nullptr && root->right==nullptr)
                return sum;
            return inorder_travesal(root->left, sum) + inorder_travesal(root->right, sum);
        }
};
