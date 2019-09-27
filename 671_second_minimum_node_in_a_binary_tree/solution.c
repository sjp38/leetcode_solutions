/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min;
int second_min;

static inline void do_cmp(int val)
{
    if (val == min)
        return;
    if (val < second_min || second_min == -1)
        second_min = val;
}

void traverse(struct TreeNode *root)
{
    if (root == NULL)
        return;
    do_cmp(root->val);
    traverse(root->left);
    traverse(root->right);
}

int findSecondMinimumValue(struct TreeNode* root){
    if (root == NULL)
        return -1;
    second_min = -1;
    min = root->val;
    traverse(root);
    return second_min;
}


