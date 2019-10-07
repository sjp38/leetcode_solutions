/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static struct stack_node {
    struct TreeNode *node;
    struct stack_node *prev;
    struct stack_node *next;
};

static struct stack_node *stack;

static int *ret_arr;
static int cap;
static int nr_nodes;

static struct stack_node *new_stacknode(struct TreeNode *node)
{
    struct stack_node *ret;
    ret = (struct stack_node *)malloc(sizeof(struct stack_node));
    ret->node = node;
    ret->prev = NULL;
    ret->next = NULL;
    return ret;
}

static void push(struct TreeNode *node)
{
    struct stack_node *sn;
    sn = new_stacknode(node);
    sn->prev = stack;
    if (stack != NULL)
        stack->next = sn;
    stack = sn;
}

static struct TreeNode *pop(void)
{
    struct stack_node *sn;
    struct TreeNode *node;
    if (stack == NULL)
        return NULL;
    sn = stack;
    node = sn->node;
    stack = stack->prev;
    free(sn);
    return node;
}

static void init_ret_arr(int capa)
{
    cap = capa;
    ret_arr = (int *)malloc(sizeof(int) * cap);
    nr_nodes = 0;
}

static void append_ret_arr(int val)
{
    if (nr_nodes == cap) {
        cap *= 2;
        ret_arr = (int *)realloc(ret_arr, sizeof(int) * cap);
    }
    ret_arr[nr_nodes++] = val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode *node;

    init_ret_arr(10);
    stack = new_stacknode(root);
    while (stack) {
        node = pop();
        if (node == NULL)
            continue;
        append_ret_arr(node->val);
        push(node->right);
        push(node->left);
    }
    *returnSize = nr_nodes;
    return ret_arr;
}
