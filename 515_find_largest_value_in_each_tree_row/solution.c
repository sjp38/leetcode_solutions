/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *answers;
int nr_answers;
int cap_answers;

void init_answers(int cap)
{
    nr_answers = 0;
    cap_answers = cap;
    answers = (int *)malloc(sizeof(int) * cap);
}

void add_answer(int answer)
{
    if (nr_answers == cap_answers) {
        cap_answers *= 2;
        answers = (int *)realloc(answers, sizeof(int) * cap_answers);
    }
    answers[nr_answers++] = answer;
}

void trav(struct TreeNode *node, int depth)
{
    if (!node)
        return;
    if (nr_answers <= depth) {
        add_answer(node->val);
    } else {
        if (answers[depth] < node->val) {
            answers[depth] = node->val;
        }
    }
    trav(node->left, depth + 1);
    trav(node->right, depth + 1);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    init_answers(10);
    trav(root, 0);
    *returnSize = nr_answers;
    return answers;
}
