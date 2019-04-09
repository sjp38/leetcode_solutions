/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

double *sums;
int *nr_nodes;
int height;

void average(struct TreeNode *entry, int level) {
	if (!entry)
		return;

	sums[level] += entry->val;
	nr_nodes[level]++;

	average(entry->left, level + 1);
	average(entry->right, level + 1);
}

void heightof(struct TreeNode* node, int level) {
	if (!node)
		return 0;

	heightof(node->left, level + 1);
	heightof(node->right, level + 1);

	if (level > height)
		height = level;
}

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
	int i;
	double *res;

	height = 0;
	heightof(root, 0);
	sums = (double *)calloc(sizeof(double), height + 1);
	nr_nodes = (int *)calloc(sizeof(int), height + 1);
	res = (double *)calloc(sizeof(double), height + 1);

	average(root, 0);

	for (i = 0; i < height + 1; i++) {
		res[i] = sums[i] / nr_nodes[i];
	}

	*returnSize = height + 1;
	return res;
}
