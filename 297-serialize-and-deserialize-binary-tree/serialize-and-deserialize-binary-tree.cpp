/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "N";
        }
        queue<TreeNode*>q;
        q.push(root);
        string ans;
        while(q.size()){
            TreeNode* f=q.front();
            q.pop();
            if(f==nullptr){
                ans=ans+"N"+",";
                continue;
            }
            else
            ans+=to_string(f->val)+",";
            
            q.push(f->left);
            q.push(f->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss,val,',');
        if(val=="N"){
            return nullptr;
        }
        TreeNode*root=new TreeNode(stoi(val));
        queue<TreeNode*>q;
        q.push(root);
        while(getline(ss,val,',')){
            TreeNode*node=q.front();
            q.pop();
            if(val!="N"){
                TreeNode*n=new TreeNode(stoi(val));
                node->left=n;
                q.push(n);
            }
            else{
                node->left=nullptr;
            }
            getline(ss,val,',');
            if(val!="N"){
                TreeNode*n=new TreeNode(stoi(val));
                node->right=n;
                q.push(n);
            }
            else{
                node->right=nullptr;
            }
        }
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));