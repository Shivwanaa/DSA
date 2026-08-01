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
    ListNode*getkth(ListNode* head, int k){
        while(head && k){
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*d=new ListNode(0,head);
        ListNode*curr=head;
        ListNode*gp=d;
        while(true){
            ListNode*kth=getkth(gp,k);
            if(!kth){
                break;
            }
            ListNode*nxt=kth->next;
            ListNode*curr=gp->next;
            ListNode*prev=kth->next;
            while(curr!=nxt){
                ListNode*t=curr->next;
                curr->next=prev;
                prev=curr;
                curr=t;
            }
            ListNode*temp=gp->next;
            gp->next=kth;
            gp=temp;
        }
        return d->next;
    }
};