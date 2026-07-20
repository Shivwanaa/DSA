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
    bool check2(TreeNode* root, TreeNode* subRoot){
        if(root && !subRoot){
            return false;
        }
        if(!root && subRoot){
            return false;
        }
        if(!root && !subRoot){
            return true;
        }
        if(root->val!=subRoot->val ){
            return false;
        }
        return check2(root->left,subRoot->left) && check2(root->right,subRoot->right);
    }
    bool check1(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot){
            return false;
        }
        if(!root){
            return false;
        }
        if(root->val==subRoot->val && check2(root,subRoot)){
            return true;
        }
        return check1(root->left,subRoot)||check1(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return check1(root,subRoot);
    }
};