/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int max_depth;

void count_max_depth(struct TreeNode *node, int depth)
{
    if (node == NULL)
        return;
    count_max_depth(node->left, depth + 1);
    count_max_depth(node->right, depth + 1);
    if (max_depth < depth)
        max_depth = depth;
}

int maxDepth(struct TreeNode* root){
    max_depth = 0;
    
    count_max_depth(root, 1);
    
    return max_depth;
}
