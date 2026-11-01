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
TreeNode*ans;
    void check(TreeNode* root, int val){
        if(!root){
            return;
        }
        if(root->val<val){
            check(root->right,val);
        }
        else if(root->val>val){
            check(root->left,val);
        }
        else{
            ans=root;
            return;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        check(root,val);
        return ans;
    }
};