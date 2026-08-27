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
vector<string>ans;
    void check(TreeNode* root,string t){
        // if(!root){
        //     return;
        // }
        
        if(!root->left && !root->right){
            ans.push_back(t+to_string(root->val));
            return ;
        }
        t=t+to_string(root->val);
        t=t+"->";
        if(root->left)
        check(root->left,t);
        if(root->right)
        check(root->right,t);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        check(root,"");
        return ans;
    }
};