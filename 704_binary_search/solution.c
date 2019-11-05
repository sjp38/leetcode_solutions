int search(int* nums, int numsSize, int target){
    int l, r, m;
    for (l = 0, r = numsSize - 1, m = (l + r) / 2;
         l <= r;
         m = (l + r) / 2) {
        if (nums[m] < target)
            l = m + 1;
        else if (nums[m] > target)
            r = m - 1;
        else
            return m;
    }
    return -1;
}
