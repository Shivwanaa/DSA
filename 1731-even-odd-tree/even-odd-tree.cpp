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
    bool isEvenOddTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        vector<int>m;
        while(q.size()){
            auto[node,l]=q.front();
            q.pop();
            if(m.size()>l){
                if(l%2==0){
                    if(m[l]>=node->val || node->val%2==0){
                        return false;
                    }
                    else{
                        m[l]=node->val;
                    }
                }
                else{
                    if(m[l]<=node->val || node->val%2==1){
                        return false;
                    }
                    else{
                        m[l]=node->val;
                    }
                }
            }
            else{
            int level=m.size();
            if(level%2==0 && node->val%2==0){
                return false;
            }
            if(level%2==1 && node->val%2==1){
                return false;
            }
            m.push_back(node->val);
            }
            if(node->left){
                q.push({node->left,l+1});
            }
            if(node->right){
                q.push({node->right,l+1});
            }
        }
        return true;
    }
};