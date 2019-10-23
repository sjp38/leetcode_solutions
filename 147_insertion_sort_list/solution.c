/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode *head_next, *sorted, *cursor, *prev;
    if (head == NULL)
        return NULL;
    sorted = head;
    head = head->next;
    sorted->next = NULL;
    while (head) {
        head_next = head->next;
        for (cursor = sorted, prev = NULL; cursor; cursor = cursor->next) {
            if (head->val < cursor->val)
                break;
            prev= cursor;
        }
        
        if (prev)
            prev->next = head;
        else
            sorted = head;
        head->next = cursor;
        head = head_next;
    }
    return sorted;
}
