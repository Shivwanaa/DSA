/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* check(Node*root,unordered_map<Node*,Node*>&m){
        if(!root){
            return nullptr;
        }
        if(m.find(root)!=m.end()){
            return m[root];
        }
        m[root]=new Node(root->val);
        for(auto i:root->neighbors){
            m[root]->neighbors.push_back(check(i,m));
        }
        return m[root];
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>m;
        check(node,m);
        return m[node];
    }
};