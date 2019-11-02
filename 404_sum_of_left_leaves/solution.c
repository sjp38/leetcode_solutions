/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void trav(struct TreeNode *node, bool is_left, int *sum)
{
    if (!node)
        return;
    trav(node->left, true, sum);
    trav(node->right, false, sum);
    if (is_left && !node->left && !node->right)
        *sum += node->val;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int sum = 0;
    trav(root, false, &sum);
    return sum;
}
