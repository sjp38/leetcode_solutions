int intcmp(const void *l, const void *r) {
	return *(int *)l - *(int *)r;
}

int findLHS(int* nums, int numsSize) {
	int i, ret, nr, pnr, nr_nr, nr_pnr;

	if (numsSize == 0)
		return 0;

	qsort(nums, numsSize, sizeof(int), intcmp);

	nr = nums[0];
	nr_nr = 0;
	nr_pnr = 0;
	ret = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != nr) {
			if (nr_pnr && nr - pnr == 1 && nr_nr + nr_pnr > ret)
				ret = nr_nr + nr_pnr;
			nr_pnr = nr_nr;
			pnr = nr;
			nr = nums[i];
			nr_nr = 0;
		}
		nr_nr++;
	}
	if (nr_pnr && nr - pnr == 1 && nr_nr + nr_pnr > ret)
		ret = nr_nr + nr_pnr;

	return ret;
}
