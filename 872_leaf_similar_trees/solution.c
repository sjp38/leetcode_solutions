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

int idx_leaf = 0;
bool cmp_leafs(struct TreeNode *root, struct dibuf *leafs) {
    if (!root->left && !root->right) {
        if (idx_leaf >= leafs->sz)
            return false;
        if (root->val != leafs->buf[idx_leaf])
            return false;
        idx_leaf++;
    }
    if (root->left && !cmp_leafs(root->left, leafs))
        return false;
    if (root->right && !cmp_leafs(root->right, leafs))
        return false;
    return true;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    struct dibuf l;
    idx_leaf = 0;
    dibuf_init(&l, 4);
    leafs(root1, &l);
    return cmp_leafs(root2, &l);
}
