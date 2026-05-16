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
    Node* check(map<Node*,Node*>&m,Node*node){
        if(!node){
            return node;
        }
        if(m.find(node)!=m.end()){
            return m[node];
        }
        Node*a=new Node(node->val);
        m[node]=a;
        for(auto i:node->neighbors){
            a->neighbors.push_back(check(m,i));
        }
        return m[node];
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node*a=new Node(node->val);
        map<Node*,Node*>m;
        unordered_set<Node*>v;
        return check(m,node);
    }
};