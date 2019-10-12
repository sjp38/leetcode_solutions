/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *last_node;
int min_diff;
void trav(struct TreeNode *node)
{
    int diff;
    if (node == NULL)
        return;
    trav(node->left);
    if (last_node != NULL) {
        /* node->val is larger than last_val because we are in in-order */
        diff = node->val - last_node->val;
        if (diff < min_diff || min_diff == -1)
            min_diff = diff;
    }
    last_node = node;
    trav(node->right);
}

int minDiffInBST(struct TreeNode* root){
    last_node = NULL;
    min_diff = -1;
    trav(root);
    return min_diff;
}
