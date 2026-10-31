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
    void check(TreeNode* root,int value){
        if(!root){
            return;
        }
        if(value<=root->val){
            ans++;
        }
        check(root->left,max(value,root->val));
        check(root->right,max(value,root->val));
    }
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        check(root,root->val);
        return ans;
    }
};