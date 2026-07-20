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
int ans=-1e9;
    int maxh(TreeNode*root){
        if(!root){
            return 0;
        }
        int p= root->val+max(maxh(root->left),maxh(root->right));
        return max(p,0);
    }
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        int l=maxh(root->left);
        int r=maxh(root->right);
        ans=max(ans,l+r+root->val);
        ans=max(ans,root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};