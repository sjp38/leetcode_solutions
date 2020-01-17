/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int longest;

int trav(struct TreeNode *node)
{
    int left_length;
    int right_length;
    int left = 0, right = 0, len;
    
    if (!node)
        return 0;
    left_length = trav(node->left);
    right_length = trav(node->right);
    
    if (node->left && node->left->val == node->val)
        left = left_length + 1;
    if (node->right && node->right->val == node->val)
        right = right_length + 1;
    len = left + right;
    if (len > longest)
        longest = len;
    return left > right ? left : right;
}

int longestUnivaluePath(struct TreeNode* root){
    longest = 0;
    trav(root);
    return longest;
}
