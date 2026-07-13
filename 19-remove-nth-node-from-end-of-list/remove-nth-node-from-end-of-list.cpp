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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*s=head;
        ListNode*f=head;
        while(n-- && f){
            f=f->next;
        }
        if(!f){
            return head->next;
        }
        while(f!=nullptr){
            if(f->next==nullptr){
                s->next=s->next->next;
            }
            s=s->next;
            f=f->next;
        }
        
        return head;
    }
};