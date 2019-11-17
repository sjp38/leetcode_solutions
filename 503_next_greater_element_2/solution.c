/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *ret;
    int i, j;
    ret = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j != i; j++) {
            if (j == numsSize) {
                j = -1;
                continue;
            }
            if (nums[j] > nums[i]) {
                ret[i] = nums[j];
                break;
            }
        }
        if (i == j)
            ret[i] = -1;
    }
    return ret;
}
