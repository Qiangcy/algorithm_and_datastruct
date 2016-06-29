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
        TreeNode* invertTree(TreeNode* root) {
            if(root == nullptr)
                return nullptr;
            /* if(root->left==nullptr && root->right==nullptr) */
            /*     return root; */
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
};

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
        TreeNode* invertTree(TreeNode* root) {
            if(root == nullptr)
                return nullptr;
            stack<TreeNode*> my_stack;
            my_stack.push(root);
            while(!my_stack.empty()) {
                TreeNode* node = my_stack.top();
                my_stack.pop();

                /* cout<<"node is "<<node->val<<endl; */
                TreeNode* tmp = node->left;
                node->left = node->right;
                node->right = tmp;
                if(node->left)
                    my_stack.push(node->left);
                if(node->right)
                    my_stack.push(node->right);
            }
            return root;
        }
};

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
        TreeNode* invertTree(TreeNode* root) {
            if(root == nullptr)
                return nullptr;
            queue<TreeNode*> my_queue;
            my_queue.push(root);
            while(!my_queue.empty()) {
                TreeNode* node = my_queue.front();
                my_queue.pop();

                /* cout<<"node is "<<node->val<<endl; */
                TreeNode* tmp = node->left;
                node->left = node->right;
                node->right = tmp;
                if(node->left)
                    my_queue.push(node->left);
                if(node->right)
                    my_queue.push(node->right);
            }
            return root;
        }
};
