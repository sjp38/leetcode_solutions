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
    n_nodes = (struct ListNode **)calloc(n + 1, sizeof(struct ListNode *));
    
    for (node = head; node != NULL; node = node->next)
        n_nodes[tail++ % (n + 1)] = node;
    h = tail % (n + 1);
    if (n_nodes[h] == NULL) {
        free(n_nodes);
        return head->next;
    }
    prev = n_nodes[h];
    free(n_nodes);
    prev->next = prev->next->next;
    return head;
}
