/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int *answer;
	int i, j;

	answer = (int *)malloc(sizeof(int) * 2);

	for (i = 0; i < numsSize; i++) {
		for (j = 0; j < numsSize; j++) {
			if (i == j)
				continue;
			if (nums[i] + nums[j] == target) {
				answer[0] = i;
				answer[1] = j;
				return answer;
			}
		}
	}
	return NULL;
}
