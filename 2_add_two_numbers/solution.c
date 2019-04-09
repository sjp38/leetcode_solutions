struct ListNode *appendNode(struct ListNode *tail, int val) {
	struct ListNode *l;

	l = (struct ListNode *)malloc(sizeof(struct ListNode));
	l->val = val;
	l->next = NULL;
	if (tail)
		tail->next = l;

	return l;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *answer, *tail = NULL;
	int v1, v2, v;
	bool carry = false, first = true;

	while (l1 || l2) {
		v1 = 0;
		v2 = 0;

		if (l1) {
			v1 = l1->val;
			l1 = l1->next;
		}
		if (l2) {
			v2 = l2->val;
			l2 = l2->next;
		}
		v = v1 + v2;
		if (carry) {
			v += 1;
			carry = false;
		}
		if (v >= 10) {
			v -= 10;
			carry = true;
		}
		tail = appendNode(tail, v);
		if (first) {
			answer = tail;
			first = false;
		}
	}
	if (carry)
		tail = appendNode(tail, 1);
	return answer;
}
