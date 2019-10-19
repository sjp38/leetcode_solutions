/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int idx_first_no_nine, offset;
    int i;
    int *ret;
    for (i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] != 9)
            break;
    }
    idx_first_no_nine = i;
    offset = idx_first_no_nine == -1 ? 1 : 0;
    *returnSize = digitsSize + offset;
    ret = (int *)calloc(*returnSize, sizeof(int));
    for (i = 0; i <= idx_first_no_nine; i++)
        ret[i + offset] = digits[i];
    ret[idx_first_no_nine + offset]++;
    return ret;
}
