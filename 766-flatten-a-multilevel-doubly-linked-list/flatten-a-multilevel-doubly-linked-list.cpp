/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr){
            return head;
        }
        Node*curr=head;
        while(curr){
            if(curr->child){
                Node*t=curr->next;
                Node* child=curr->child;
                curr->next=child;
                child->prev=curr;
                curr->child=nullptr;
                Node*tail=child;
                while(tail->next){
                    tail=tail->next;
                }
                tail->next=t;
                if(t)
                t->prev=tail;
            }
            curr=curr->next;
        }
        return head;
    }
};