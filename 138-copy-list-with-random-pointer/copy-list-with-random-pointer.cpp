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
        map<Node*,Node*>m;
        Node*h=head;
        while(h){
            Node*a=new Node(h->val);
            m[h]=a;
            h=h->next;
        }
        h=head;
        while(h){
            Node*nxt=h->next;
            Node*rand=h->random;
            m[h]->next=m[nxt];
            m[h]->random=m[rand];
            h=h->next;
        }
        return m[head];
    }
};