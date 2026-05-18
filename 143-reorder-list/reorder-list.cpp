/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        //split the list into 2 part 
        //first find the middle of the list
        ListNode*s=head;
        ListNode*f=head;
        if(!head||head->next==nullptr){
            return;
        }
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode*m=s->next;
        s->next=nullptr;
        //reverse
        ListNode*n=nullptr;
        while(m){
            ListNode*t=m->next;
            m->next=n;
            n=m;
            m=t;
        }
        ListNode*h=head;
        while(n!=nullptr && h!=nullptr){
            ListNode*t=h->next;
            h->next=n;
            h=t;
            ListNode*nd=n->next;
            n->next=t;
            n=nd;
        }
    }
};