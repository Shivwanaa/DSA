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
unordered_map<TreeNode*,int>dp;
    int rob(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }
        int p=root->val;
        if(root->left && root->right){
            p=root->val+rob(root->left->left)+rob(root->left->right)+rob(root->right->left)+rob(root->right->right);
        }
        else if(root->left){
            p=root->val+rob(root->left->left)+rob(root->left->right);
        }
        else if(root->right){
            p=root->val+rob(root->right->left)+rob(root->right->right);
        }
        int np=rob(root->left)+rob(root->right);
        return dp[root]=max(p,np);
    }
};