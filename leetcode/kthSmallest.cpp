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
        int kthSmallest(TreeNode* root, int k) {
            int res = 0;
            traverse(root, k, res);
            return res;
        }
    private:
        void traverse(TreeNode* root, int &k, int &res) {
            if(root == nullptr)
                return;
            if(root->left != nullptr)
                traverse(root->left, k, res);
            --k;
            if(k == 0) {
                res = root->val;
                return;
            }
            if(root->right != nullptr)
                traverse(root->right, k, res);
            return;
        }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> my_stack;
        TreeNode* node = root;
        while(node || !my_stack.empty()) {
            while(node != nullptr) {
                my_stack.push(node);
                node = node->left;
            }
            node = my_stack.top();
            --k;
            if(k == 0)
                break;
            my_stack.pop();
            node = node->right;
        }
        return node->val;
    }
};
