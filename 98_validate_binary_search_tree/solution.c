/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *last_node;

bool validate(struct TreeNode *node)
{
    if (!node)
        return true;
    if (!validate(node->left))
        return false;
    if (last_node && last_node->val >= node->val)
        return false;
    last_node = node;
    if (!validate(node->right))
        return false;
    return true;
}

bool isValidBST(struct TreeNode* root){
    last_node = NULL;
    return validate(root);
}
