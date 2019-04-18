int cmp(const void *l, const void *r) {
	return *(int *)l - *(int *)r;
}

int paircmp(const void *l, const void *r) {
	int *li, *ri;

	li = (int *)l, ri = (int *)r;
	return ri[1] - li[1];
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
	int *num_nr_arr;
	int i, j;
	int *ret;

	qsort(nums, numsSize, sizeof(int), cmp);

	/*
	 * We can reduce memory overhead by adopting dynamic length array,
	 * though
	 */
	num_nr_arr = (int *)malloc(sizeof(int) * numsSize * 2);

	/* nums is not empty */
	num_nr_arr[0] = nums[0], num_nr_arr[1] = 1;
	for (i = 1, j = 0; i < numsSize; i++) {
		if (num_nr_arr[j] == nums[i]) {
			num_nr_arr[j + 1]++;
		} else {
			j += 2;
			num_nr_arr[j] = nums[i];
			num_nr_arr[j + 1] = 1;
		}
	}

	qsort(num_nr_arr, j / 2 + 1, sizeof(int) * 2, paircmp);

	*returnSize = k;
	ret = (int *)malloc(sizeof(int) * k);
	for (i = 0; i < k; i++) {
		ret[i] = num_nr_arr[i * 2];
	}
	free(num_nr_arr);

	return ret;
}
