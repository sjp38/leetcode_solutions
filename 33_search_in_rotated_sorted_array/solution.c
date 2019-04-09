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

#define realidx(idx, start, len) (idx + start >= len ? idx + start - len : idx + start)

int __search(int *nums, int nr_nums, int real_start, int target) {
	int start, end, mid;
	int v;

	start = 0;
	end = nr_nums - 1;

	while (start <= end) {
		mid = (start + end) / 2;
		v = nums[realidx(mid, real_start, nr_nums)];
		if (v == target)
			return realidx(mid, real_start, nr_nums);

		if (v < target)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}

int search(int* nums, int numsSize, int target) {
	int idx_m;
	int i, cursor;

	if (numsSize == 0)
		return -1;

	idx_m = idx_min(nums, numsSize);

	return __search(nums, numsSize, idx_m, target);
}
