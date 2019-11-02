/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sum;

void trav(struct TreeNode *node, bool is_left)
{
    if (!node)
        return;
    if (is_left && !node->left && !node->right)
        sum += node->val;
    trav(node->left, true);
    trav(node->right, false);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    sum = 0;
    trav(root, false);
    return sum;
}
