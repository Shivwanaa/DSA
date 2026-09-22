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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,vector<TreeNode*>>m;
        stack<TreeNode*>s;
        s.push(root);
        TreeNode*ini;
        while(s.size()){
            TreeNode*r=s.top();
            s.pop();
            if(r->val==start){
                ini=r;
            }
            if(r->left){
                m[r].push_back(r->left);
                m[r->left].push_back(r);
                s.push(r->left);
            }
            if(r->right){
                m[r].push_back(r->right);
                m[r->right].push_back(r);
                s.push(r->right);
            }
        }
        queue<TreeNode*>q;
        q.push(ini);
        int t=0;
        unordered_set<TreeNode*>v;
        while(q.size()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode*fr=q.front();
                q.pop();
                v.insert(fr);
                for(auto i:m[fr]){
                    if(!v.count(i))
                    q.push(i);
                }
            }
            t++;
        }
        return t-1;
    }

};