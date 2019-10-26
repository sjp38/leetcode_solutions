/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max_occurrence;
int curr_occurrence;
int prev_value;

void get_max_occurrence(struct TreeNode *node)
{
    if (node == NULL)
        return;
    get_max_occurrence(node->left);
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
    if (curr_occurrence > max_occurrence)
        max_occurrence = curr_occurrence;
    get_max_occurrence(node->right);
}

int *modes;
int nr_modes;
int cap_modes;

void add_mode(int mode)
{
    if (nr_modes == cap_modes) {
        cap_modes *= 2;
        modes = (int *)realloc(modes, sizeof(int) * cap_modes);
    }
    modes[nr_modes++] = mode;
}

void get_modes(struct TreeNode *node)
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
    if (curr_occurrence == max_occurrence)
        add_mode(node->val);
    get_modes(node->right);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMode(struct TreeNode* root, int* returnSize){
    max_occurrence = 0;
    curr_occurrence = 0;
    
    get_max_occurrence(root);
    if (modes)
        free(modes);
    nr_modes = 0;
    cap_modes = 100;
    modes = (int *)malloc(sizeof(int) * cap_modes);
    curr_occurrence = 0;
    get_modes(root);
    *returnSize = nr_modes;
    return modes;
}
