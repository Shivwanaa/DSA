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
    void check(TreeNode* root,int num){
        num=num*10+root->val;
        if(!root->left && !root->right){
            ans=ans+num;
        }
        if(root->left)
        check(root->left,num);
        if(root->right)
        check(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        check(root,0);
        return ans;
    }
};