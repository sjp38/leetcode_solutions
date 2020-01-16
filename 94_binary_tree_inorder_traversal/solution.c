/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int *ret;
int cap;
int nr_nodes;

void darr_init(int capa)
{
    cap = capa;
    ret = (int *)malloc(sizeof(int) * capa);
    nr_nodes = 0;
}

void darr_add(int val)
{
    if (nr_nodes == cap) {
        cap *= 2;
        ret = (int *)realloc(ret, sizeof(int) * cap);
    }
    ret[nr_nodes++] = val;
}

void trav(struct TreeNode *node)
{
    if (!node)
        return;
    
    trav(node->left);
    darr_add(node->val);
    trav(node->right);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    darr_init(100);
    trav(root);
    *returnSize = nr_nodes;
    return ret;
}
