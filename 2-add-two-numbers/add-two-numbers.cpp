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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*d=new ListNode(0);
        ListNode*t=d;
        int c=0;
        int s=0;
        while(l1||l2||c>0){
            if(l1 && l2){
                s=l1->val+l2->val+c;
                c=s/10;
                s=s%10;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){
                s=l1->val+c;
                c=s/10;
                s=s%10;
                l1=l1->next;
            
            }
            else if(l2){
                s=l2->val+c;
                c=s/10;
                s=s%10;
                l2=l2->next;
            }
            else{
                s=c;
                c=0;
            }
            ListNode*t=new ListNode(s);
            d->next=t;
            d=d->next;
        }
        return t->next;
    }
};