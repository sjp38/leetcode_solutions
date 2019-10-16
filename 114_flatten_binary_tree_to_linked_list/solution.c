/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *prev;

void trav(struct TreeNode *node)
{
    struct TreeNode *l, *r;
    if (!node)
        return;
    l = node->left;
    r = node->right;
    if (prev) {
        prev->left = NULL;
        prev->right = node;
    }
    prev = node;
    trav(l);
    trav(r);
}

void flatten(struct TreeNode* root){
    prev = NULL;
    trav(root);
}
