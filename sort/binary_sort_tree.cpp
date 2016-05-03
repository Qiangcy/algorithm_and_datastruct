#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;
bool cmp(int i, int j) { return i<j; }
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};


void add_node(TreeNode* root, TreeNode* my_node)
{
    //cout<<"try to add "<<my_node->val<<endl;
    if(my_node->val > root->val) {
        if(!root->right) {
            root->right = my_node;
            //cout<<"right add "<<my_node->val<<endl;
            return;
        }else {
            add_node(root->right, my_node);
        }
    }
    if(my_node->val < root->val) {
        if(!root->left) {
            root->left = my_node;
            //cout<<"left add "<<my_node->val<<endl;
            return;
        }else {
            add_node(root->left, my_node);
        }
    }
}

void travel(TreeNode* node, int level, vector<vector<int>> &res) {
    if(!node)
        return;
    if(level > res.size())
        res.push_back(vector<int>());
    res[level-1].push_back(node->val);
    travel(node->left,  level+1, res);
    travel(node->right, level+1, res);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    travel(root, 1, res);
    return res;
}

void delete_node(TreeNode* root)
{
    if(!root)
        return;
    delete_node(root->left);
    delete_node(root->right);
    delete root;
}

int main(void)
{
#ifdef LOCAL_PROJECT
    freopen ("input.txt", "r", stdin);
    //freopen("a.out","w",stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif

    int n, val;
    cin>>n;
    TreeNode *root = new TreeNode;
    for(int i=0; i<n; ++i) {
        cin>>val;
        if(i == 0) {
            root->val = val;
            continue;
        }
        TreeNode *tmp = new TreeNode;
        tmp->val = val;
        add_node(root, tmp);
    }
    vector<vector<int>> res = levelOrder(root);
    cout<<"level order of the tree: "<<endl;
    for(auto it= begin(res); it!=end(res); ++it)
    {
        for(auto tmp : *it)
            cout<<tmp<<" ";
        cout<<endl;
    }

    return 0;
}
