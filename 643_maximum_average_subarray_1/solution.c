double findMaxAverage(int* nums, int numsSize, int k){
    int i;
    int sum = 0;
    int maxsum;
    for (i = 0; i < k; i++) {
        sum += nums[i];
    }
    maxsum = sum;
    for (; i < numsSize; i++) {
        sum += (nums[i] - nums[i - k]);
        if (sum > maxsum)
            maxsum = sum;
    }
    return (double)maxsum / k;
}
