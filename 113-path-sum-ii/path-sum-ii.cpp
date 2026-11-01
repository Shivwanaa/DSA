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
vector<vector<int>>ans;
    void check(TreeNode* root, int targetSum,vector<int>tp){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            if(targetSum-root->val==0){
                tp.push_back(root->val);
                ans.push_back(tp);
                return;
            }
        }
        tp.push_back(root->val);
        check(root->left,targetSum-root->val,tp);
        check(root->right,targetSum-root->val,tp);
        tp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        check(root,targetSum,{});
        return ans;
    }
};