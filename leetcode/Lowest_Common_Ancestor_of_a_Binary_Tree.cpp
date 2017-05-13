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

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* res = nullptr;
            vector<TreeNode*> p_vector, q_vector;

            bool finished_flag = false;
            get_path(root, p, p_vector, finished_flag);
            finished_flag = false;
            get_path(root, q, q_vector, finished_flag);

            for(auto it=p_vector.rbegin(); it!=p_vector.rend(); ++it) {
                if(find(q_vector.rbegin(), q_vector.rend(), *it) != q_vector.rend()) {
                    res = *it;
                    break;
                }
            }
            return res;
        }

    private:
        void get_path(TreeNode *root, TreeNode *target,
                vector<TreeNode*> &node_vector, bool &finished_flag) {
            if(!finished_flag) {
                if(root == nullptr)
                    return;
                node_vector.push_back(root);
                if(root == target) {
                    finished_flag = true;
                    return;
                }
                get_path(root->left, target, node_vector, finished_flag);
                get_path(root->right, target, node_vector, finished_flag);
                if(!finished_flag)
                    node_vector.pop_back();
            }
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode *parent1 = lowestCommonAncestor(root->left,  p, q);
        TreeNode *parent2 = lowestCommonAncestor(root->right, p, q);
        if(parent1 && parent2)
            return root;
        else
            return parent1?parent1:parent2;
    }
};
