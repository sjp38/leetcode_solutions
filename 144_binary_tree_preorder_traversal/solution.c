/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *ret_arr;
int cap;
int nr_nodes;

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

static void traverse(struct TreeNode *node)
{
    if (!node)
        return;
    append_ret_arr(node->val);
    traverse(node->left);
    traverse(node->right);
    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    init_ret_arr(10);
    traverse(root);
    *returnSize = nr_nodes;
    return ret_arr;
}
