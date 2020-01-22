/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool is_symmetric(struct TreeNode *l, struct TreeNode *r)
{
    if (!l && !r)
        return true;
    if (!l || !r)
        return false;
    if (l->val != r->val)
        return false;
    if (!is_symmetric(l->left, r->right))
        return false;
    if (!is_symmetric(l->right, r->left))
        return false;
    return true;
}

bool isSymmetric(struct TreeNode* root){
    if (!root)
        return true;
    return is_symmetric(root->left, root->right);
}
