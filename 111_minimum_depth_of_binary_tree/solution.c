/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int depthof(struct TreeNode *node, int level) {
    int l = INT_MAX, r = INT_MAX;
    
    if (!node->left && !node->right)
        return level;
    if (node->left)
        l = depthof(node->left, level + 1);
    if (node->right)
        r = depthof(node->right, level + 1);
    return l > r ? r: l;
}

int minDepth(struct TreeNode* root){
    if (!root)
        return 0;
    return depthof(root, 1);
}
