/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int last_depth;
int val;

void traverse(struct TreeNode *node, int depth)
{
    if (node == NULL)
        return;
    traverse(node->left, depth + 1);
    if (depth > last_depth) {
        last_depth = depth;
        val = node->val;
    }
    traverse(node->right, depth + 1);
}

int findBottomLeftValue(struct TreeNode* root){
    last_depth = -1;
    traverse(root, 0);
    return val;
}
