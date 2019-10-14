/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *node, *prev;
    struct ListNode **n_nodes;
    int h = 0, tail = 0;
    n_nodes = (struct ListNode **)malloc(sizeof(struct ListNode *) * (n + 1));
    
    for (node = head; node != NULL; node = node->next) {
        n_nodes[tail++ % (n + 1)] = node;
        if (tail > n + 1)
            h = (h + 1) % (n + 1);
    }
    if (h == 0 && tail == n)
        return head->next;
    prev = n_nodes[h];
    prev->next = prev->next->next;
    return head;
}
