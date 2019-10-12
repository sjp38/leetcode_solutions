/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int get_tilt_sum(struct TreeNode *node, int *tilt)
{
    int ls, rs;
    if (node == NULL)
        return 0;
    ls = get_tilt_sum(node->left, tilt);
    rs = get_tilt_sum(node->right, tilt);
    
    *tilt += ls > rs ? ls - rs : rs - ls;
    
    return ls + rs + node->val;
}

int findTilt(struct TreeNode* root){
    int ls, rs;
    int tilt = 0;
    if (root == NULL)
        return 0;
    get_tilt_sum(root, &tilt);
    return tilt;
}
