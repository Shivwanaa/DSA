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
    void check(TreeNode* root,string tp){
        if(!root){
            
            return;
        }
        if(!root->left && !root->right){
            tp=tp+to_string(root->val);
            ans.push_back(tp);
            return;
        }
        tp=tp+to_string(root->val)+"->";
        check(root->left,tp);
        check(root->right,tp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        check(root,"");
        return ans;
    }
};