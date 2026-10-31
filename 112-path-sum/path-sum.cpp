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
bool ans=false;
    void check(TreeNode* root, int targetSum){
        if(!root){
            return ;
        }
        if(targetSum-root->val ==0 && !root->left && !root->right){
            ans=true;
            return;
        }
        
        check(root->left,targetSum-root->val);
        check(root->right,targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        check(root,targetSum);
        return ans;
    }
};