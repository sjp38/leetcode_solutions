/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a, *b;
    struct ListNode *a_last = NULL, *b_last = NULL;
    
    a = headA, b = headB;
    while (true) {
        if (!a || !b)
            return NULL;
        if (a == b)
            return a;
        if (a->next) {
            a = a->next;
        } else {
            a_last = a;
            a = headB;
            if (b_last && a_last != b_last)
                return NULL;
        }
        if (b->next) {
            b = b->next;
        } else {
            b_last = b;
            b = headA;
            if (a_last && a_last != b_last)
                return NULL;
        }
    }
}
