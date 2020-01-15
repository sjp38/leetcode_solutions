/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int ret = 0;
    for (; head; head = head->next) {
        ret = ret << 1;
        if (head->val)
            ret++;
    }
    return ret;
}
