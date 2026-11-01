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
    void check(TreeNode* root, int targetSum,unordered_map<long long,int>&m,long long ts){
        if(!root){
            return ;
        }
        ts=ts+root->val;
        ans=ans+m[ts-targetSum];
        m[ts]++;
        check(root->left,targetSum,m,ts);
        check(root->right,targetSum,m,ts);
        m[ts]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>m;
        m[0]=1;
        check(root,targetSum,m,0);
        
        return ans;
    }
};