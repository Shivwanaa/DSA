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
bool ans;
    bool check1(TreeNode* root, TreeNode* subRoot){
        if(!subRoot && !root){
            return true;
        }
        if(!subRoot||!root){
            return false;
        }
        if(subRoot->val!=root->val){
            return false;
        }
        return check1(root->left,subRoot->left)&&check1(root->right,subRoot->right);
    }
    void check(TreeNode* root, TreeNode* subRoot){
        if(!root){
            return;
        }
        if(subRoot->val==root->val){
            ans=ans||check1(root,subRoot);
        }
        check(root->left,subRoot);
        check(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        check(root,subRoot);
        return ans;
    }
};