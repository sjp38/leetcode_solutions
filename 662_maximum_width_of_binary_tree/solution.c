/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct qnode {
    struct TreeNode *node;
    int lv;
    unsigned long pos;
};

struct qnode *queue;
unsigned long idx_enq;
unsigned long idx_deq;
unsigned long cap_queue;

void pr_q(void)
{
    struct qnode *qn;
    int i;
    printf("==queue==\n");
    for (i = idx_deq; i < idx_enq; i++) {
        qn = &queue[i];
        printf("%p %d %d %d\n", qn->node, (qn->node ? qn->node->val : -1), qn->lv, qn->pos);
    }
    printf("=========\n");
}

void enq(struct TreeNode *node, int lv, int pos)
{
    //printf("enq %p %d %d %d\n", node, node ? node->val : -1, lv, pos);
    //printf("%d %d %d\n", idx_enq, idx_deq, cap_queue);
    struct qnode *qn;
    if (idx_enq == cap_queue - 1) {
        cap_queue *= 2;
        queue = realloc(queue, sizeof(struct qnode) * cap_queue);
    }
    qn = &queue[idx_enq++];
    qn->node = node;
    qn->lv = lv;
    qn->pos = pos;
}

struct qnode deq(void)
{
    //printf("deq\n");
    return queue[idx_deq++];
}

bool queue_empty(void)
{
    return idx_deq == idx_enq;
}

void init_queue(void)
{
    cap_queue = 10;
    queue = (struct qnode *)malloc(sizeof(struct qnode) * cap_queue);
    idx_enq = 0;
    idx_deq = 0;
}

int widthOfBinaryTree(struct TreeNode* root){
    struct qnode qn;
    int current_lv, leftmost_pos, ret, distance;
    
    init_queue();
    current_lv = leftmost_pos = ret = 0;
    enq(root, current_lv, leftmost_pos);
    while (!queue_empty()) {
        qn = deq();
        //printf("1\n");
        //pr_q();
        if (qn.node == NULL)
            continue;
        //printf("11\n");
        enq(qn.node->left, qn.lv + 1, qn.pos * 2 + 1);
        //printf("12\n");
        enq(qn.node->right, qn.lv + 1, qn.pos * 2 + 2);
        //printf("13\n");
        if (current_lv != qn.lv) {
            current_lv = qn.lv;
            leftmost_pos = qn.pos;
        }
        distance = qn.pos - leftmost_pos + 1;
        ret = ret > distance ? ret : distance;
        //printf("2\n");
    }
    return ret;
}
