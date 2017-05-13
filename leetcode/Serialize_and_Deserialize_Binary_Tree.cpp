/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize_helper(TreeNode* root, )

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        serialize(root->left);
        serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
