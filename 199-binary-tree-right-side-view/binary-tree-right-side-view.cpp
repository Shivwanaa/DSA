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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        vector<int>ans;
        q.push({root,0});
        int c=0;
        if(!root){
            return ans;
        }
        while(q.size()){
            auto[r,l]=q.front();
            q.pop();
            if(ans.size()==l){
                ans.push_back(r->val);
            }
            if(r->right){
                q.push({r->right,l+1});
            }
            if(r->left){
                q.push({r->left,l+1});
            }
            // if(r->right){
            //     q.push({r->right,l+1});
            // }
        }
        return ans;
    }
};