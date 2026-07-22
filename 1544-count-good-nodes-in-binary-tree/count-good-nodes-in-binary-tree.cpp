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
    void check(TreeNode* root,int val){
        if(!root){
            return ;
        }
        if(root->val>=val){
            cout<<root->val<<" ";
            ans++;
            check(root->left,root->val);
            check(root->right,root->val);
        }
        else{
            check(root->left,val);
            check(root->right,val);
        }
    }
    int goodNodes(TreeNode* root) {
        check(root,-1e9);
        return ans;
    }
};