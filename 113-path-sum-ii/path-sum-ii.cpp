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
    void check(TreeNode* root, int targetSum,vector<int>temp){
        if(!root){
            return ;
        }
        targetSum=targetSum-root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum==0){
                ans.push_back(temp);
                return;
            }
        }
        check(root->left,targetSum,temp);
        check(root->right,targetSum,temp);
         
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        check(root,targetSum,temp);
        return ans;
    }
};