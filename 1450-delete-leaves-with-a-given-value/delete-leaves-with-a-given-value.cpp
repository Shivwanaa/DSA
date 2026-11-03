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
    TreeNode*check(TreeNode* root, int target){
        if(!root){
            return nullptr;
        }
        TreeNode*l=check(root->left,target);
        TreeNode*r=check(root->right,target);
        root->left=l;
        root->right=r;
        if(root->val==target && !l && !r){
            return nullptr;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return check(root,target);
        // return root;
    }
};