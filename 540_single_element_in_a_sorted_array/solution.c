int singleNonDuplicate(int* nums, int numsSize){
    int l, r, mid;
    if (numsSize == 1)
        return nums[0];
    for (l = 0, r = numsSize - 1; l != r;) {
        mid = (l + r) / 2;
        if ((mid == 0 || mid == numsSize - 1) ||
            (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]))
            return nums[mid];
        if (nums[mid] == nums[mid - 1]) {
            if (mid % 2 == 0)
                r = mid;
            else
                l = mid + 1;
        } else {
            if (mid % 2 == 0)
                l = mid + 1;
            else
                r = mid;
        }
    }
    return nums[l];
}
