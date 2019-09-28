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

void shrink_queue(void)
{
    int nr_nodes;
    struct qnode *new_q;
    nr_nodes = idx_enq - idx_deq;
    new_q = (struct qnode *)malloc(sizeof(struct qnode) * cap_queue);
    memcpy(new_q, &queue[idx_deq], sizeof(struct qnode) * nr_nodes);
    idx_enq -= idx_deq;
    idx_deq = 0;
    queue = new_q;
}

void enq(struct TreeNode *node, int lv, int pos)
{
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
    if (idx_deq > cap_queue / 2)
        shrink_queue();
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
        if (qn.node == NULL)
            continue;
        enq(qn.node->left, qn.lv + 1, qn.pos * 2 + 1);
        enq(qn.node->right, qn.lv + 1, qn.pos * 2 + 2);
        if (current_lv != qn.lv) {
            current_lv = qn.lv;
            leftmost_pos = qn.pos;
        }
        distance = qn.pos - leftmost_pos + 1;
        ret = ret > distance ? ret : distance;
    }
    return ret;
}
