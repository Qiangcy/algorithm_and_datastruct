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
    int get_depth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return 1+max(get_depth(root->left), get_depth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        int left = get_depth(root->left);
        int right = get_depth(root->right);
        return abs(left-right) <= 1 &&
            isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution {
public:
    int judge_fun(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int left =  judge_fun(root->left);
        if(left == -1)
            return -1;
        int right = judge_fun(root->right);
        if(right == -1)
            return -1;
        if(abs(left-right) > 1)
            return -1;
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        return judge_fun(root)!=-1;
    }
};
