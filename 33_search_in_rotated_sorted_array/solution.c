int idx_min(int *nums, int numsSize) {
	int start, end, mid, v, prev;

	start = 0;
	end = numsSize - 1;
	while (start <= end) {
		mid = (start + end) / 2;

		if (mid == 0)
			prev = numsSize - 1;
		else
			prev = mid - 1;

		if (nums[mid] < nums[prev])
			return mid;

		if (mid && nums[mid] < nums[0])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return 0;
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
