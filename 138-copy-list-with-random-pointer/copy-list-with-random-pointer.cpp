/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>m;
        Node*temp=head;
        while(temp){
            Node*t=new Node(temp->val);
            m[temp]=t;
            temp=temp->next;
        }
        for(auto i:m){
            Node*n=i.first->next;
            Node*r=i.first->random;
            i.second->next=(n?m[n]:nullptr);
            i.second->random=(r?m[r]:nullptr);
        }
        return m[head];
    }
};