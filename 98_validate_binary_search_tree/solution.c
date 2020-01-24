/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int last_val;

bool validate(struct TreeNode *node)
{
    if (!node)
        return true;
    if (!validate(node->left))
        return false;
    if (last_val == -1)
        last_val = node->val;
    else if (node->val <= last_val)
        return false;
    last_val = node->val;
    if (!validate(node->right))
        return false;
    return true;
}

bool isValidBST(struct TreeNode* root){
    last_val = -1;
    return validate(root);
}
