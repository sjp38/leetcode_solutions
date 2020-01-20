/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode *node;
    
    for (node = root; node;) {
        if (node->val == val)
            return node;
        if (node->val < val)
            node = node->right;
        else if (node->val > val)
            node = node->left;
    }
    return NULL;
}
