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
    Node* check(unordered_map<Node*,Node*>&m,Node* node){
        if(!node){
            return nullptr;
        }
        if(m.find(node)!=m.end()){
            return m[node];
        }
        Node*t=new Node(node->val);
        m[node]=t;
        for(auto i:node->neighbors){
            m[node]->neighbors.push_back(check(m,i));
        }
        return m[node];
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>m;
        
        
        check(m,node);
        return m[node];
    }
};