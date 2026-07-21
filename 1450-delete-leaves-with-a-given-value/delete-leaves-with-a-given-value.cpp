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
    TreeNode* check(TreeNode* root, int target){
        if(!root){
            return nullptr;
        }
        root->left=check(root->left,target);
        root->right=check(root->right,target);
        if(root->left==nullptr && root->right==nullptr && root->val==target){
            return nullptr;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return check(root,target);
        
    }
};