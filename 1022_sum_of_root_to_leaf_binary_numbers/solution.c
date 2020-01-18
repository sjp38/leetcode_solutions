/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int answer;

void trav(struct TreeNode *node, int val)
{
    if (!node)
        return;
    val = val << 1;
    val += node->val;
    if (!node->left && !node->right)
        answer += val;
    trav(node->left, val);
    trav(node->right, val);
}

int sumRootToLeaf(struct TreeNode* root){
    answer = 0;
    trav(root, 0);
    return answer;
}
