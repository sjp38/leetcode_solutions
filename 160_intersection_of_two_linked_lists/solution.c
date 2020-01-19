/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a, *b;
    
    for (a = headA; a; a = a->next) {
        for (b = headB; b; b = b->next) {
            if (a == b)
                return a;
        }
    }
    return NULL;
}
