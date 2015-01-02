/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *rhead = NULL;
        if(head == NULL) {
            return rhead;
        }
        else {
            rhead = new RandomListNode(head->label);
        }
        RandomListNode *p = head->next, *q, *pre = rhead, *pnt;
        
        while(p != NULL) {
            q = new RandomListNode(p->label);
            pre->next = q;
            pre = pre->next;
            p = p->next;
        }
        
        p = head;
        q = rhead;

        while(p != NULL) {
            pnt = head;
            pre = rhead;
            if(p->random == NULL) {
                q->random = NULL;
            }
            else {
                while(pnt != p->random && pnt != NULL) {
                    pnt = pnt->next;
                    pre = pre->next;
                }
                q->random = pre;
            }
            p = p->next;
            q = q->next;
        }
        return rhead;
    }
};
