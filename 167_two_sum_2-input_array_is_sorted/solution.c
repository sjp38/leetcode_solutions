/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *ret;
    int i, j;
    ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (i = 0; i < numbersSize - 1; i++) {
        for (j = i + 1; j < numbersSize; j++) {
            if (numbers[i] + numbers[j] == target) {
                ret[0] = i + 1;
                ret[1] = j + 1;
                return ret;
            }
            if (numbers[i] + numbers[j] > target) {
                break;
            }
        }
    }
    return NULL;
}
