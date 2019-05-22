void moveZeroes(int* nums, int numsSize){
    /* shift each non-zeroes with first zero: O(n) */
    int nr_zeroes = 0;
    int i, j;
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            nr_zeroes++;
            continue;
        }
        if (nr_zeroes == 0)
            continue;
        nums[i - nr_zeroes] = nums[i];
        nums[i] = 0;
    }
}
