int **merge_arrays(int **a, int sz_a, int **b, int sz_b) {
	int **ret;
	int i;

	ret = (int **)malloc(sizeof(int *) * (sz_a + sz_b));

	for (i = 0; i < sz_a + sz_b; i++) {
		if (i < sz_a)
			ret[i] = a[i];
		else
			ret[i] = b[i - sz_a];
	}

	free(a);
	free(b);

	return ret;
}

int **add_at_head(int nr, int **subpermutes, int sz_subperms, int nr_nums) {
	int **ret, *nums;
	int i, j;

	ret = (int **)malloc(sizeof(int *) * sz_subperms);
	for (i = 0; i < sz_subperms; i++) {
		nums = (int *)malloc(sizeof(int) * (nr_nums + 1));
		nums[0] = nr;
		for (j = 1; j < nr_nums + 1; j++) {
			nums[j] = subpermutes[i][j - 1];
		}
		free(subpermutes[i]);
		ret[i] = nums;
	}
	free(subpermutes);
	return ret;
}

static inline int **permute_mini(int *nums, int numsSize, int *returnSize) {
	int **ret, i;

	if (numsSize == 0) {
		*returnSize = 0;
		return NULL;
	}
	if (numsSize == 1) {
		*returnSize = 1;
		ret = (int **)malloc(sizeof(int *) * *returnSize);
		ret[0] = (int *)malloc(sizeof(int) * numsSize);
		ret[0][0] = nums[0];

		return ret;
	}
	*returnSize = 2;
	ret = (int **)malloc(sizeof(int *) * *returnSize);
	for (i = 0; i < *returnSize; i++) {
		ret[i] = (int *)malloc(sizeof(int) * numsSize);
		ret[i][0] = nums[i == 0 ? 0 : 1];
		ret[i][1] = nums[i == 0 ? 1 : 0];
	}
	return ret;
}

/**
 *  * Return an array of arrays of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
int** permute(int* nums, int numsSize, int* returnSize) {
	int **ret = NULL;
	int *subnums;
	int **subpermutes;
	int sz_subperms;
	int i, j;

	if (numsSize < 3)
		return permute_mini(nums, numsSize, returnSize);

	/* Now recursive */
	*returnSize = 0;
	for (i = 0; i < numsSize; i++) {
		subnums = (int *)malloc(sizeof(int) * numsSize - 1);
		for (j = 0; j < numsSize - 1; j++) {
			if (j < i)
				subnums[j] = nums[j];
			else
				subnums[j] = nums[j + 1];
		}
		subpermutes = permute(subnums, numsSize - 1, &sz_subperms);
		subpermutes = add_at_head(nums[i], subpermutes, sz_subperms, numsSize - 1);

		ret = merge_arrays(ret, *returnSize, subpermutes, sz_subperms);
		*returnSize += sz_subperms;
	}

	return ret;
}
