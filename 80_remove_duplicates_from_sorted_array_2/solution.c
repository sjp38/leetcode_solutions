int removeDuplicates(int* nums, int numsSize){
    int i, nr_removed = 0;
    if (numsSize < 3)
        return numsSize;
    for (i = 2; i < numsSize; i++) {
        if (nr_removed)
            nums[i - nr_removed] = nums[i];
        if (nums[i - nr_removed] == nums[i - nr_removed - 1] &&
           nums[i - nr_removed - 1] == nums[i - nr_removed - 2])
            nr_removed++;
    }
    return numsSize - nr_removed;
}
