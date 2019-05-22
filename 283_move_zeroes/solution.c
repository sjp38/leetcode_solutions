void moveZeroes(int* nums, int numsSize){
    int i, j;
    char finished;
    
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == 0) {
            finished = 1;
            for (j = i +1; j < numsSize; j++) {
                nums[j - 1] = nums[j];
                if (nums[j] != 0)
                    finished = 0;
            }
            if (finished)
                return;
            nums[numsSize - 1] = 0;
            i--;
            numsSize--;
        }
    }
}
