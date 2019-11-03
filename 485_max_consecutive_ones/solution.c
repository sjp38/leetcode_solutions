#define max(a,b) (a > b ? a : b)

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int maxlen = 0;
    int cons_start_idx = -1;
    int i;
    for (i = 0; i <= numsSize; i++) {
        if (i == numsSize || nums[i] == 0) {
            if (cons_start_idx != -1) {
                maxlen = max(maxlen, i - cons_start_idx);
                cons_start_idx = -1;
            }
        } else {
            if (cons_start_idx == -1)
                cons_start_idx = i;
        }
    }
    return maxlen;
}
