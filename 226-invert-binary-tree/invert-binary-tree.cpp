/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* check(TreeNode*root){
        if(!root){
            return nullptr;
        }
        TreeNode*r=check(root->left);
        TreeNode*l=check(root->right);
        root->left=l;
        root->right=r;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        check(root);
        return root;
    }
};