/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *tail;
    int len, shift_left, i;
    if (head == NULL)
        return NULL;
    for (tail = head, len = 1; tail->next != NULL; tail = tail->next, len++)
        ;
    tail->next = head;
    shift_left = len - (k % len);
    for (i = 0; i < shift_left; i++, head = head->next, tail = tail->next)
        ;
    tail->next = NULL;
    return head;
}
