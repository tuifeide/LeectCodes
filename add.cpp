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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int sum = 0, push = 0;
        while(l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + push;
            push = 0;
            if(sum > 9) {
                sum -= 10;
                push = 1;
            }
            p->next = new ListNode(sum);
            p =  p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL) {
            while(l2 != NULL){
                sum = l2->val + push;
                push = 0;
                if(sum > 9) {
                    sum -= 10;
                    push = 1;
                }
                p->next = new ListNode(sum);
                p =  p->next;
                l2 = l2->next;
            }
        }
        else if(l2 == NULL) {
            while(l1 != NULL){
                sum = l1->val + push;
                push = 0;
                if(sum > 9) {
                    sum -= 10;
                    push = 1;
                }
                p->next = new ListNode(sum);
                p =  p->next;
                l1 = l1->next;
            }
        }
        if(push == 1) {
            p->next = new ListNode(push);
        }
        p = head;
        head = head->next;
        delete p;
        return head;
    }
};
