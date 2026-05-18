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
        //calc the len , then remove accordingly
        ListNode*s=head;
        ListNode*f=head;
        int l=0;
        while(s){
            s=s->next;
            l++;
        }
        if(l-n-1==-1){
            return head->next;
        }
        int a=0;
        while(a<l-n-1 && f){
            f=f->next;
            a++;
        }
        if(f && f->next)
        f->next=f->next->next;
        return head;
    }
};