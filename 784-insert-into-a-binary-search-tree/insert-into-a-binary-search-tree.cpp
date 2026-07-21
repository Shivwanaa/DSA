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
    TreeNode*check(TreeNode* root, int val,int min,int max){
        if(!root){
            TreeNode*n=new TreeNode(val);
            return n;
        }
        if(val<root->val){
            root->left=check(root->left,val,min,root->val);
        }
        else{
            root->right=check(root->right,val,root->val,max);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return check(root,val,INT_MAX,INT_MIN);
    }
};