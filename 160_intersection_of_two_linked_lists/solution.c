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
        if (!a->next) {
            a_last = a;
            a = headB;
        } else {
            a = a->next;
        }
        if (!b->next) {
            b_last = b;
            b = headA;
        } else {
            b = b->next;
        }
        if (a_last && b_last && a_last != b_last)
            return NULL;
    }
}
