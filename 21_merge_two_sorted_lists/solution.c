/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ret = NULL, *ir = NULL, **small;
    if (!l1 && !l2)
        return NULL;
    for (ir = ret; l1 && l2;) {
        if (l1->val < l2->val)
            small = &l1;
        else
            small = &l2;
        if (ir == NULL)
            ret = *small;
        else
            ir->next = *small;
        ir = *small;
        *small = (*small)->next;
    }
    if (ret == NULL)
        return l1 ? l1: l2;
    ir->next = l1 == NULL ? l2 : l1;
    return ret;
}
