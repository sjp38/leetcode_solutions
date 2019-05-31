/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *insert(int *nums, int nr_nums) {
    struct TreeNode *node;
    int max, idx_max;
    int i;
    
    if (nr_nums == 0)
        return NULL;
    
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    
    max = nums[0];
    idx_max = 0;
    for (i = 1; i < nr_nums; i++) {
        if (nums[i] > max) {
            max = nums[i];
            idx_max = i;
        }
    }
    node->val = max;
    node->left = insert(&nums[0], idx_max);
    node->right = insert(&nums[idx_max + 1], nr_nums - idx_max - 1);
    
    return node;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    return insert(nums, numsSize);
}
