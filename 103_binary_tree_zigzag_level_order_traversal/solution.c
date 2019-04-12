struct dynarr {
	int *buf;
	int len;
	int cap;
};

void init_dynarr(struct dynarr *da, int cap) {
	da->buf = (int *)malloc(sizeof(int) * cap);
	da->len = 0;
	da->cap = cap;
}

struct dynarr *new_dynarr(int cap) {
	struct dynarr *da;

	da = (struct dynarr *)malloc(sizeof(struct dynarr));
	init_dynarr(da, cap);

	return da;
}

void append(struct dynarr *da, int val) {
	if (da->len == da->cap) {
		da->cap *= 2;
		da->buf = realloc(da->buf, sizeof(int) * da->cap);
	}
	da->buf[da->len++] = val;
}

struct dynarr *col_for(int level, struct dynarr **cols, int *nr_cols) {
	struct dynarr *new_cols, *ret;
	int i;

	if (*nr_cols < level + 1) {
		new_cols = (struct dynarr *)malloc(sizeof(struct dynarr) * (level + 1));
		for (i = 0; i < *nr_cols; i++)
			new_cols[i] = (*cols)[i];
		for (i = *nr_cols; i < level + 1; i++)
			new_cols[i].buf = NULL;
		*cols = new_cols;
		*nr_cols = level + 1;
	}
	ret = &(*cols)[level];
	if (!ret->buf)
		init_dynarr(ret, 1);
	return ret;
}

void __zigzag(struct TreeNode *node, int level, struct dynarr **cols, int *nr_cols) {
	struct dynarr *c;
	int i;

	if (node == NULL)
		return;
	__zigzag(node->left, level + 1, cols, nr_cols);
	__zigzag(node->right, level + 1, cols, nr_cols);

	c = col_for(level, cols, nr_cols);
	append(c, node->val);
}

int *flip_arr(int *arr, int sz) {
	int i;
	int *ret;

	ret = (int *)malloc(sizeof(int) * sz);
	for (i = 0; i < sz; i++)
		ret[i] = arr[sz - i - 1];
	return ret;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
	struct dynarr *cols = NULL;
	int nr_cols = 0;
	int i;
	int **ret;
	int *colszs;

	__zigzag(root, 0, &cols, &nr_cols);

	colszs = (int *)malloc(sizeof(int) * nr_cols);
	ret = (int **)malloc(sizeof(int *) * nr_cols);
	for (i = 0; i < nr_cols; i++) {
		if (i % 2 == 0) {
			ret[i] = cols[i].buf;
			colszs[i] = cols[i].len;
			continue;
		}
		ret[i] = flip_arr(cols[i].buf, cols[i].len);
		colszs[i] = cols[i].len;
		free(cols[i].buf);
	}
	*columnSizes = colszs;
	*returnSize = nr_cols;
	return ret;
}
