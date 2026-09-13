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
int c=0;
    int check(TreeNode* root, int k){
        if(!root){
            return -1;
        }
        if(c==k){
            return root->val;
        }
        int l=check(root->left,k);
        if(l!=-1){
            return l;
        }
        c++;
        if(c==k){
            return root->val;
        }
        return check(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return check(root,k);
    }
};