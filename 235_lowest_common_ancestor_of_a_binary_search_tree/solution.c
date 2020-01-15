/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *do_search(struct TreeNode *node, struct TreeNode *p, struct TreeNode *q)
{
    int l, r;
    struct TreeNode *answer;
    
    l = p->val < q->val ? p->val : q->val;
    r = p->val > q->val ? p->val : q->val;
    
    if (!node)
        return NULL;
    
    if (node->val >= l && node->val <= r)
        return node;
    
    if (node->val > r)
        return do_search(node->left, p, q);
    else
        return do_search(node->right, p, q);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    return do_search(root, p, q);
}
