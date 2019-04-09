int thirdMax(int* nums, int numsSize) {
    int biggest[3] = {0,};
    bool initialized[3] = {false,};
    bool duplicate = false;
    int i, j, tmp, k;
    
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 3; j++) {
            if (initialized[j] && nums[i] == biggest[j]) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) {
            duplicate = false;
            continue;
        }
        // biggest[0] < biggest[1] < biggest[2]
        for (j = 2; j >= 0; j--) {
            if (nums[i] > biggest[j] || !initialized[j]) {
                // shift lower values
                for (k = 0; k < j; k++) {
                    if (initialized[k + 1])
                        initialized[k] = true;
                    biggest[k] = biggest[k + 1];
                }
                biggest[j] = nums[i];
                initialized[j] = true;
                break;
            }
        }
    }
    
    if (initialized[0])
        return biggest[0];
    return biggest[2];
}
