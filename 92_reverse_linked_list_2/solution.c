/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode **startlink = &head;
    struct ListNode *prev;
    struct ListNode *prevprev;
    struct ListNode *node;
    int idx;
    for (node = head, idx = 1; node && idx <= n; node = node->next, idx++) {
        if (idx < m - 1)
            continue;
        if (idx == m - 1) {
            startlink = &node->next;
            continue;
        }
        if (idx == m) {
            prevprev = node;
            continue;
        }
        if (idx == m + 1)
            prev = node;
        if (idx > m + 1) {
            prev->next = prevprev;
            prevprev = prev;
            prev = node;
        }
        if (idx == n) {
            (*startlink)->next = node->next;
            node->next = prevprev;
            *startlink = node;
        }
    }
    if (m == 1)
        return *startlink;
    return head;
}
