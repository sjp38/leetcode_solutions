/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode *node, **link;
    node = root;
    while (node) {
        if (node->val > val)
            link = &node->left;
        else if (node->val < val)
            link = &node->right;
        node = *link;
    }
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    *link = node;
    return root;
}
