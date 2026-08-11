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
 struct Info {
    int minVal;
    int maxVal;
    int sum;
    bool flag;   // whether this subtree is a BST
};
class Solution {
public:
int ans=0;
    Info check(TreeNode* root){
        if(!root){
            return {INT_MAX,INT_MIN,0,true};
        }
        Info l=check(root->left);
        Info r=check(root->right);
        if(l.flag && r.flag){
            if(l.maxVal<root->val && r.minVal>root->val){
                ans=max(ans,l.sum+r.sum+root->val);
                int mini=min(l.minVal,root->val);
            int maxi=max(r.maxVal,root->val);
            return {mini,maxi,l.sum+r.sum+root->val,true};
            }
        }
       return {INT_MAX,INT_MIN,0,false};
    }
    int maxSumBST(TreeNode* root) {
        check(root);
        return ans;
    }
};