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
    int check(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+max(check(root->left),check(root->right));
    }
    void check1(TreeNode* root){
        if(!root){
            return;
        }
        int l=check(root->left);
        int r=check(root->right);
        ans=max(ans,l+r);
        check1(root->left);
        check1(root->right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        check1(root);
        return ans;
    }
};