/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define diffof(l, r) (l > r ? l - r : r - l)

int height_of(struct TreeNode *node)
{
    int lh, rh;
    
    if (!node)
        return 0;
    
    lh = height_of(node->left);
    rh = height_of(node->right);
    
    return lh > rh ? lh + 1 : rh + 1;
}

bool isBalanced(struct TreeNode* root){
    int left_height, right_height;
    
    if (!root)
        return true;
    
    left_height = height_of(root->left);
    right_height = height_of(root->right);
    if (diffof(left_height, right_height) > 1)
        return false;
    
    if (!isBalanced(root->left))
        return false;
    if (!isBalanced(root->right))
        return false;
    
    return true;
}
