int dominantIndex(int* nums, int numsSize){
    int first, second, n;
    int i, idx;
    
    if (numsSize == 1)
        return 0;
    
    if (nums[0] > nums[1]) {
        first = nums[0];
        second = nums[1];
        idx = 0;
    } else {
        first = nums[1];
        second = nums[0];
        idx = 1;
    }
    for (i = 2; i < numsSize; i++) {
        n = nums[i];
        if (n > second) {
            second = n;
        }
        if (second > first) {
            n = first;
            first = second;
            second = n;
            idx = i;
        }
    }
    if (first >= second * 2)
        return idx;
    return -1;
}
