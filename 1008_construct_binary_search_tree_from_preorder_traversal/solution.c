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
    struct TreeNode *cursor, *last_cursor;
    
    if (root == NULL)
        return node;
    cursor = root;
    last_cursor = cursor;
    while (cursor != NULL) {
        if (cursor->val > node->val) {
            last_cursor = cursor;
            cursor = cursor->left;
        }
        else if (cursor->val < node->val) {
            last_cursor = cursor;
            cursor = cursor->right;
        }
        else {
            printf("SOMETHING WRONG\n");
            return NULL;
        }
    }
    if (last_cursor->val > node->val)
        last_cursor->left = node;
    if (last_cursor->val < node->val)
        last_cursor->right = node;
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
