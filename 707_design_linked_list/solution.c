bool debug = false;
struct node {
    int val;
    struct node *next;
};

typedef struct {
    struct node *head;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    if (debug)
        printf("new list\n");
    MyLinkedList *ret;
    ret = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    ret->head = NULL;
    return ret;
}

void pr_lst(MyLinkedList *lst)
{
    if (!debug)
        return;
    struct node *n;
    for (n = lst->head; n; n = n->next)
        printf("%d ", n->val);
    printf("\n");
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    struct node *n;
    if (index < 0)
        return -1;
    for (n = obj->head; index > 0 && n != NULL ; index--, n = n->next)
        ;
    if (index > 0 || n == NULL)
        return -1;
    return n->val;
}

static struct node *new_node(int val)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->val = val;
    n->next = NULL;
    return n;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct node *n;
    n = new_node(val);
    n->next = obj->head;
    obj->head = n;
    if (debug)
        printf("add at head %d\n", val);
    pr_lst(obj);
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct node **c;
    for (c = &obj->head; *c != NULL; c = &(*c)->next)
        ;
    *c = new_node(val);
    if (debug)
        printf("add at tail %d\n", val);
    pr_lst(obj);
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct node *p, *n, *new;
    if (debug)
        printf("add at index %d %d\n", index, val);
    for (n = obj->head, p = n; n && index > 0; p = n, n = n->next, index--)
        ;
    if (index > 0)
        return;
    /* n is index-th node, p is index-1-th node or n */
    new = new_node(val);
    new->next = n;
    if (p != n)
        p->next = new;
    else
        obj->head = new;
    pr_lst(obj);
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    struct node *p, *n, *new;
    if (index < 0)
        return;
    if (debug)
        printf("delete at index %d\n", index);
    for (n = obj->head, p = n; n && index > 0; p = n, n = n->next, index--)
        ;
    if (index > 0 || n == NULL)
        return;
    /* n is index-th node, p is index-1-th node or n */
    if (p == n) {
        obj->head = n->next;
        return;
    }
    p->next = n->next;
    free(n);
    pr_lst(obj);
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
