/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct dibuf {
    int *buf;
    int cap;
    int sz;
};

void dibuf_insert(struct dibuf *b, int v) {
    if (b->cap == b->sz) {
        b->cap *= 2;
        b->buf = (int *)realloc(b->buf, sizeof(int) * b->cap);
    }
    b->buf[b->sz++] = v;
}

void dibuf_init(struct dibuf *b, int cap) {
    b->buf = (int *)malloc(sizeof(int) * cap);
    b->cap = cap;
    b->sz = 0;
}

void leafs(struct TreeNode *root, struct dibuf *buf) {
    if (root == NULL)
        return;
    if (!root->left && !root->right) {
        dibuf_insert(buf, root->val);
        return;
    }
    leafs(root->left, buf);
    leafs(root->right, buf);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    struct dibuf l, r;
    int i;

    dibuf_init(&l, 4);
    dibuf_init(&r, 4);
    leafs(root1, &l);
    leafs(root2, &r);
    if (l.sz != r.sz)
        return false;
    for (i = 0; i < l.sz; i++) {
        if (l.buf[i] != r.buf[i])
            return false;
    }
    return true;
}
