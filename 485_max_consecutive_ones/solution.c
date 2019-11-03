int findMaxConsecutiveOnes(int* nums, int numsSize){
    int maxlen = 0;
    int cons_start_idx = -1;
    int i;
    for (i = 0; i < numsSize; i++) {
        if (cons_start_idx == -1 && nums[i] == 0)
            continue;
        if (cons_start_idx == -1 && nums[i] == 1)
            cons_start_idx = i;
        if (cons_start_idx != -1 && nums[i] == 0) {
            if (maxlen < i - cons_start_idx)
                maxlen = i - cons_start_idx;
            cons_start_idx = -1;
        }
    }
    if (cons_start_idx != -1) {
        if (maxlen < i - cons_start_idx)
            maxlen = i - cons_start_idx;
    }
    return maxlen;
}
