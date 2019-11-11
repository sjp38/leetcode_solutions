/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode *node, *parent;
    node = root, parent = NULL;
    while (node) {
        parent = node;
        if (node->val > val)
            node = node->left;
        else if (node->val < val)
            node = node->right;
    }
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    if (parent->val < val)
        parent->right = node;
    else
        parent->left = node;
    return root;
}
