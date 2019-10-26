/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static bool find_max;
static int max_occurrence;
static int curr_occurrence;
static int prev_value;

static int *modes;
static int nr_modes;
static int cap_modes;

static void add_mode(int mode)
{
    if (nr_modes == cap_modes) {
        cap_modes *= 2;
        modes = (int *)realloc(modes, sizeof(int) * cap_modes);
    }
    modes[nr_modes++] = mode;
}

static void get_modes(struct TreeNode *node)
{
    if (node == NULL)
        return;
    get_modes(node->left);
    if (curr_occurrence == 0) { /* root node case */
        prev_value = node->val;
        curr_occurrence = 1;
    } else {
        if (node->val == prev_value) {
            curr_occurrence++;
        } else {
            prev_value = node->val;
            curr_occurrence = 1;
        }
    }
    if (find_max) {
        if (curr_occurrence > max_occurrence)
            max_occurrence = curr_occurrence;
    } else {
        if (curr_occurrence == max_occurrence)
            add_mode(node->val);
    }
    get_modes(node->right);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMode(struct TreeNode* root, int* returnSize){
    max_occurrence = 0;
    curr_occurrence = 0;
    
    find_max = true;
    get_modes(root);
    if (modes)
        free(modes);
    nr_modes = 0;
    cap_modes = 100;
    modes = (int *)malloc(sizeof(int) * cap_modes);
    curr_occurrence = 0;
    find_max = false;
    get_modes(root);
    *returnSize = nr_modes;
    return modes;
}
