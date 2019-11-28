/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *prev, *node;
    for (node = head, prev = NULL; node; node = node->next) {
        if (node->val == val) {
            if (prev)
                prev->next = node->next;
            else
                head = node->next;
            continue;
        }
        prev = node;
    }
    return head;
}
