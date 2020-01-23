/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int to_add;

void convert(struct TreeNode *node)
{
    if (!node)
        return;
    convert(node->right);
    node->val += to_add;
    to_add = node->val;
    convert(node->left);
}

struct TreeNode* convertBST(struct TreeNode* root){
    to_add = 0;
    convert(root);
    return root;
}
