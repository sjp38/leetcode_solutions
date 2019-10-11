/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *n1, *n2, *pn1, *pn2, *nn1, *nn2;
    struct ListNode *n, *pn;
    int lv, rv;
    pn1 = pn2 = NULL;
    for (n1 = l1, n2 = l2; n1 || n2;) {
        if (n1) {
            nn1 = n1->next;
            if (pn1)
                n1->next = pn1;
            pn1 = n1;
            if (pn1 == l1)
                pn1->next = NULL;
            n1 = nn1;
        }
        if (n2) {
            nn2 = n2->next;
            if (pn2)
                n2->next = pn2;
            pn2 = n2;
            if (pn2 == l2)
                pn2->next = NULL;
            n2 = nn2;
        }
    }
    pn = NULL;
    for (n1 = pn1, n2 = pn2; n1 || n2;) {
        lv = rv = 0;
        if (n1) {
            lv = n1->val;
            n1 = n1->next;
        }
        if (n2) {
            rv = n2->val;
            n2 = n2->next;
        }
        n = (struct ListNode *)malloc(sizeof(struct ListNode));
        n->val = lv + rv;
        if (pn) {
            if (pn->val >= 10) {
                pn->val -= 10;
                n->val += 1;
            }
        }
        n->next = pn;
        pn = n;
    }
    if (pn->val >= 10) {
        n = (struct ListNode *)malloc(sizeof(struct ListNode));
        pn->val -= 10;
        n->val = 1;
        n->next = pn;
        pn = n;
    }
    return pn;
}
