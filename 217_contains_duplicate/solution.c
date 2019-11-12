int cmp(const void *l, const void *r)
{
    return *(int *)l - *(int *)r;
}

bool containsDuplicate(int* nums, int numsSize){
    int i;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i])
            return true;
    }
    return false;
}
