void moveZeroes(int* nums, int numsSize){
    int i, j;
    
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == 0) {
            for (j = i +1; j < numsSize; j++) {
                nums[j - 1] = nums[j];   
            }
            nums[numsSize - 1] = 0;
            i--;
            numsSize--;
        }
    }
}
