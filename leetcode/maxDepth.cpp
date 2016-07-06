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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        int res = 0;
        while(!my_queue.empty()) {
            ++res;
            for(int i=0, n=my_queue.size(); i<n; ++i) {
                TreeNode* node = my_queue.front();
                my_queue.pop();
                if(node->left != nullptr)
                    my_queue.push(node->left);
                if(node->right != nullptr)
                    my_queue.push(node->right);
            }
        }
        return res;
    }
};
