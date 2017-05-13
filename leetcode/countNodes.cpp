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
        int countNodes(TreeNode* root) {
            if(root == nullptr)
                return 0;
            int left_height = 1;
            int right_height = 1;
            TreeNode *tmp = root;
            while(tmp->left) {
                left_height++;
                tmp = tmp->left;
            }
            tmp = root;
            while(tmp->right) {
                right_height++;
                tmp = tmp->right;
            }
            if(left_height == right_height)
                return pow(2, right_height)-1;

            return 1+countNodes(root->left)+countNodes(root->right);
        }
};
