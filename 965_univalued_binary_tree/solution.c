/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static bool answer;
static int prev_value;

void trav(struct TreeNode *node)
{
    if (!node)
        return;
    if (prev_value != -1 && node->val != prev_value) {
        answer = false;
        return;
    }
    prev_value = node->val;
    trav(node->left);
    trav(node->right);
}
bool isUnivalTree(struct TreeNode* root){
    prev_value = -1;
    answer = true;
    trav(root);
    return answer;
}
