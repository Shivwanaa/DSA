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
vector<int>temp;
    void check(TreeNode* root){
        if(!root){
            return;
        }
        check(root->left);
        temp.push_back(root->val);
        check(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        check(root);
        return temp[k-1];
    }
};