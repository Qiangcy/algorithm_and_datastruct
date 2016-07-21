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
        vector<string> paths;
        if(root == nullptr)
            return paths;
        stack<TreeNode*> node_stack;
        stack<string> path_string;
        node_stack.push(root);
        path_string.push(to_string(root->val));
        while(!node_stack.empty()) {
            TreeNode* node = node_stack.top();
            node_stack.pop();
            string tmp_str = path_string.top();
            path_string.pop();
            if(node->left) {
                node_stack.push(node->left);
                path_string.push(tmp_str + "->" + to_string(node->left->val));
            }
            if(node->right) {
                node_stack.push(node->right);
                path_string.push(tmp_str + "->" + to_string(node->right->val));
            }
            if(node->left==nullptr && node->right==nullptr) {
                paths.push_back(tmp_str);
            }
        }
        return paths;
    }
};
