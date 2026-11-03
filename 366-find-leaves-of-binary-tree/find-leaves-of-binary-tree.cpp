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
vector<vector<int>> ans;
    void check(TreeNode* root,TreeNode*par,vector<int>&t){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            t.push_back(root->val);
            if(par->left==root){
                par->left=nullptr;
            }
            else{
                par->right=nullptr;
            }
            return;
        }
        check(root->left,root,t);
        check(root->right,root,t);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        while(root){
        vector<int>t;
        if(!root->left && !root->right){
                ans.push_back({root->val});
                root=nullptr;
                break;
            }
        check(root,nullptr,t);
        ans.push_back(t);
        }
        return ans;
    }
};