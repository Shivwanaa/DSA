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
        stack<TreeNode*>st;
        st.push(root);
        unordered_map<TreeNode*,vector<TreeNode*>>m;
        TreeNode*inf;
        while(st.size()){
            TreeNode*top=st.top();
            st.pop();
            if(top->val==start){
                inf=top;
            }
            if(top->left){
                m[top].push_back(top->left);
                m[top->left].push_back(top);
                st.push(top->left);
            }
            if(top->right){
                m[top].push_back(top->right);
                m[top->right].push_back(top);
                st.push(top->right);
            }
        }
        queue<TreeNode*>q;
        q.push(inf);
        int t=0;
        unordered_set<TreeNode*>v;
        v.insert(inf);
        while(q.size()){
            int s=q.size();
            for(int i=0;i<s;i++){
            TreeNode*fr=q.front();
            q.pop();
            v.insert(fr);
            for(auto j:m[fr]){
                if(!v.count(j)){
                    v.insert(j);
                q.push(j);
                }
            }
            }
             if(!q.empty())
                t++;
        }
        return t;
    }
};