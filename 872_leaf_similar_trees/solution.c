/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *leafs(struct TreeNode *root, int *leaves, int *nr_leaves) {
    if (root == NULL)
        return leaves;
    if (!root->left && !root->right) {
        leaves = (int *)realloc(leaves, sizeof(int) * (*nr_leaves + 1));
        leaves[*nr_leaves] = root->val;
        *nr_leaves += 1;
        return leaves;
    }
    leaves = leafs(root->left, leaves, nr_leaves);
    leaves = leafs(root->right, leaves, nr_leaves);
    return leaves;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int *l_leaves = NULL, *r_leaves = NULL;
    int nr_l = 0, nr_r = 0;
    int i;
    l_leaves = leafs(root1, NULL, &nr_l);
    r_leaves = leafs(root2, NULL, &nr_r);
    if (nr_l != nr_r)
        return false;
    for (i = 0; i < nr_l; i++) {
        if (l_leaves[i] != r_leaves[i])
            return false;
    }
    return true;
}
