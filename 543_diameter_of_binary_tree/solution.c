/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static int ans = 1;

int depth(struct TreeNode *node)
{
    int l, r;
    if (!node)
        return 0;
    l = depth(node->left);
    r = depth(node->right);
    if (ans < l + r + 1)
        ans = l + r + 1;
    if (l > r)
        return l + 1;
    return r + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    ans = 1;
    depth(root);
    return ans - 1;
}
