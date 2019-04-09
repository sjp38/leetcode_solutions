int idx_min(int *nums, int numsSize) {
	int i;
	int ret = -1;

	ret = 0;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] < nums[ret])
			ret = i;
	}

	return ret;
}

int search(int* nums, int numsSize, int target) {
	int idx_m;
	int i, cursor;

	if (numsSize == 0)
		return -1;

	idx_m = idx_min(nums, numsSize);

	for (i = 0; i < numsSize; i++) {
		cursor = idx_m + i;
		if (cursor >= numsSize)
			cursor -= numsSize;

		if (nums[cursor] > target)
			return -1;
		else if (nums[cursor] == target)
			return cursor;
	}
	return -1;
}
