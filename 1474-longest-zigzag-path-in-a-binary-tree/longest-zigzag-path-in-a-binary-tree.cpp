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
    pair<int,int>check(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto l=check(root->left);
        auto r=check(root->right);
        int gol=0,gor=0;
        if(root->left){
            gol=1+l.second;
        }
        if(root->right){
            gor=1+r.first;
        }
        ans=max(ans,gol);
        ans=max(ans,gor);
        return {gol,gor};
    }
    int longestZigZag(TreeNode* root) {
        check(root);
        return ans;
    }
};