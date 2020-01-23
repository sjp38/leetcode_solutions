/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int total_sum;

int total_sum_of(struct TreeNode *node)
{
    int sum;
    if (!node)
        return 0;
    sum = node->val;
    sum += total_sum_of(node->left);
    sum += total_sum_of(node->right);
    return sum;
}

void convert(struct TreeNode *node)
{
    if (!node)
        return;
    convert(node->left);
    total_sum -= node->val;
    node->val = node->val + total_sum;
    convert(node->right);
}

struct TreeNode* convertBST(struct TreeNode* root){
    total_sum = total_sum_of(root);
    convert(root);
    return root;
}
