/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *node;
    int len;
    for (node = head, len = 0; node != NULL; node = node->next, len++)
        ;
    if (len == n)
        return head->next;
    len -= (n + 1);
    for (node = head; len > 0; node = node->next, len--)
        ;
    node->next = node->next->next;
    return head;
}
