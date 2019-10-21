double findMaxAverage(int* nums, int numsSize, int k){
    int i;
    int sum = 0;
    int maxsum;
    for (i = 0; i < numsSize; i++) {
        if (i < k) {
            sum += nums[i];
            maxsum = sum;
            continue;
        }
        sum += (nums[i] - nums[i - k]);
        if (sum > maxsum)
            maxsum = sum;
    }
    return (double)maxsum / k;
}
