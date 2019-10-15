/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int prune(struct TreeNode *node, struct TreeNode **link)
{
    int l, r;
    if (node == NULL)
        return 0;
    l = prune(node->left, &node->left);
    r = prune(node->right, &node->right);
    if (l + r + node->val == 0 && link)
        *link = NULL;
    return l + r + node->val;
    
}

struct TreeNode* pruneTree(struct TreeNode* root){
    if (prune(root, NULL) == 0)
        return NULL;
    return root;
}
