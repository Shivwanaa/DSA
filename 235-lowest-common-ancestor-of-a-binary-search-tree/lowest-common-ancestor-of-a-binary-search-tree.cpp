/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode*ans;
    void check(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return ;
        }
        if((root->val>=p->val && root->val<=q->val)||(root->val<=p->val && root->val>=q->val)){
            ans=root;
        }
        if(p->val<root->val && q->val<root->val)
        check(root->left,p,q);
        if(p->val>root->val && q->val>root->val)
        check(root->right,p,q);  
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {     
        check(root,p,q); 
        return ans;        
    }
};