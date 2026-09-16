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
    void check(TreeNode* root,int maxi){
        if(!root){
            return;
        }
        int a;
        if(maxi<=root->val){
            maxi=root->val;
            ans++;
        }
        check(root->left,maxi);
        check(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        //max from each dfs path
        check(root,root->val);
        return ans;
    }
};