/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode **darr;
int nr_nodes;
int cap;

void darr_init(int capa)
{
    cap = capa;
    darr = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * cap);
    nr_nodes = 0;
}

void darr_add(struct TreeNode *node)
{
    if (nr_nodes == cap) {
        cap *= 2;
        darr = (struct TreeNode **)realloc(darr, sizeof(struct TreeNode *) * cap);
    }
    darr[nr_nodes++] = node;
}

void trav(struct TreeNode *node)
{
    if (!node)
        return;
    trav(node->left);
    darr_add(node);
    trav(node->right);
}

struct TreeNode* increasingBST(struct TreeNode* root){
    int i;
    if (!root)
        return NULL;
    darr_init(10);
    trav(root);
    for (i = 1; i < nr_nodes; i++) {
        darr[i - 1]->left = NULL;
        darr[i - 1]->right = darr[i];
    }
    darr[i - 1]->left = NULL;
    return darr[0];
}
