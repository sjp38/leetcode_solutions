int searchInsert(int* nums, int numsSize, int target){
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] >= target)
            break;
    }
    return i;
}
