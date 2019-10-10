/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static inline struct TreeNode *newnode(int val)
{
    static struct TreeNode *newnode;
    newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = val;
    return newnode;
}

static struct TreeNode *tree_insert(struct TreeNode *root, int val)
{
    struct TreeNode **pp, *node;
    if (root == NULL)
        return newnode(val);
    node = root;
    while (node) {
        if (node->val > val) {
            pp = &node->left;
        } else {
            pp = &node->right;
        }
        node = *pp;
    }
    *pp = newnode(val);
    return root;
}

static struct TreeNode *insert(struct TreeNode *root, int *nums, int nr_nums)
{
    int mid = nr_nums / 2;
    if (nr_nums <= 0)
        return root;
    root = tree_insert(root, nums[mid]);
    if (nr_nums > 1) {
        root = insert(root, nums, mid);
        root = insert(root, &nums[mid + 1], nr_nums - mid - 1);
    }
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    int i;
    struct TreeNode *root = NULL;
    root = insert(root, nums, numsSize);
    return root;
}
