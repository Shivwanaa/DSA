/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*s=head;
        ListNode*f=head;
        if(!head||!head->next){
            return nullptr;
        }
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f){
                ListNode*h=head;
                while(h!=s){
                    h=h->next;
                    s=s->next;
                }
                return s;
            }
        }
        return nullptr;
    }
};