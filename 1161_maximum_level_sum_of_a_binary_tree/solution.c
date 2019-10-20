/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *sums;
int cap_sums;

void get_sums(struct TreeNode *node, int lv)
{
    if (node == NULL)
        return;
    if (lv >= cap_sums) {
        sums = (int *)realloc(sums, sizeof(int) * cap_sums * 2);
        memset(&sums[cap_sums], 0, cap_sums);
        cap_sums *= 2;
    }
    sums[lv] += node->val;
    get_sums(node->left, lv + 1);
    get_sums(node->right, lv + 1);
}

int maxLevelSum(struct TreeNode* root){
    int ret;
    int lv;
    if (root == NULL)
        printf("WTF?\n");
    cap_sums = 100;
    sums = (int *)calloc(cap_sums, sizeof(int));
    get_sums(root, 0);
    for (lv = 0, ret = 0; lv < cap_sums; lv++) {
        if (sums[lv] > sums[ret])
            ret = lv;
    }
    return ret + 1;
}
