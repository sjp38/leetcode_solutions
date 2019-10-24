/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int x_parent, y_parent;
int x_depth, y_depth;

void check_set(int val, int cval, int pval, int depth, int *pparent, int *pdepth)
{
    if (val == cval) {
        *pparent = pval;
        *pdepth = depth;
    }
}

void get_parents(struct TreeNode *node, int depth, int x, int y)
{
    if (node->left) {
        check_set(x, node->left->val, node->val, depth + 1, &x_parent, &x_depth);
        check_set(y, node->left->val, node->val, depth + 1, &y_parent, &y_depth);
        get_parents(node->left, depth + 1, x, y);
    }
    if (node->right) {
        check_set(x, node->right->val, node->val, depth + 1, &x_parent, &x_depth);
        check_set(y, node->right->val, node->val, depth + 1, &y_parent, &y_depth);
        get_parents(node->right, depth + 1, x, y);
    }
}

bool isCousins(struct TreeNode* root, int x, int y) {
    if (root == NULL)
        return false;
    get_parents(root, 0, x, y);
    if (x_depth == y_depth && x_parent != y_parent)
        return true;
    return false;
}
