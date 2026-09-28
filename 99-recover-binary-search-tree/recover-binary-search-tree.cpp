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
TreeNode*first=nullptr;
TreeNode*second=nullptr;
TreeNode*prev=nullptr;
    void check(TreeNode* root){
        if(!root){
            return;
        }
        check(root->left);
        if(prev!=nullptr && prev->val>root->val){
            second=root;
            if(first==nullptr){
                first=prev;
            }
            else{
                return;
            }
        }
        prev=root;
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
        
        check(root);
        swap(first->val,second->val);
    }
};