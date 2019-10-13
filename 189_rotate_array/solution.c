void rotate(int* nums, int numsSize, int k){
    int *newarr;
    int to_idx;
    int i, j;
    newarr = (int *)malloc(sizeof(int) * numsSize);
    for (i = 0; i < numsSize; i++) {
        to_idx = (i + k) % numsSize;
        newarr[to_idx] = nums[i];
    }
    memcpy(nums, newarr, sizeof(int) * numsSize);
    free(newarr);
}
