typedef struct {
    int *nums;
    int nr_nums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *ret;
    ret = (NumArray *)malloc(sizeof(NumArray));
    ret->nums = nums;
    ret->nr_nums = numsSize;
    return ret;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0;
    int c;
    for (c = i; c <= j && c < obj->nr_nums; c++)
        sum += obj->nums[c];
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
