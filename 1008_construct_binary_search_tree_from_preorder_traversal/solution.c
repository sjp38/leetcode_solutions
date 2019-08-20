/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *insert(struct TreeNode *root, struct TreeNode *node)
{
    struct TreeNode *cursor, **candidate;
    
    if (root == NULL)
        return node;
    cursor = root;
    while (cursor != NULL) {
        if (cursor->val > node->val) {
            candidate = &cursor->left;
            cursor = cursor->left;
        }
        else if (cursor->val < node->val) {
            candidate = &cursor->right;
            cursor = cursor->right;
        }
        /* the values are distinct */
    }
    *candidate = node;
    return root;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    int i;
    struct TreeNode *root, *node;
    
    for (root = NULL, i = 0; i < preorderSize; i++) {
        node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node->val = preorder[i];
        node->left = NULL;
        node->right = NULL;
        root = insert(root, node);
    }
    return root;
}
