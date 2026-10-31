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
int ans=0;
    void check(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            if(!root->left->left && !root->left->right)
                ans=ans+root->left->val;
        check(root->left);
        }
        check(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        check(root);
        return ans;
    }
};