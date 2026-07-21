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
    TreeNode*check(TreeNode* root, int key){
        if(!root){
            return nullptr;
        }
        if(root->val==key){
            if(root->right && root->left){
                TreeNode*tmp=root->right;
                while(tmp->left){
                    tmp=tmp->left;
                }
                root->val=tmp->val;
                root->right= check(root->right,tmp->val);
            }
            else if(root->right){
                return root->right;
            }
            else{
                return root->left;
            }
        }
        if(root->val>key)
        root->left=check(root->left,key);
        if(root->val<key)
        root->right=check(root->right,key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return check(root,key);
    }
};