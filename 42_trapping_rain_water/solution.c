int trap(int* height, int heightSize){
    int water = 0;
    int left_highest, right_highest = 1, lower;
    int i, j;
    if (heightSize <= 2)
        return 0;
    left_highest = 0;
    for (i = 1; i < heightSize - 1; i++) {
        if (height[i - 1] > height[left_highest])
            left_highest = i - 1;
        if (i >= right_highest) {
            right_highest = heightSize - 1;
            for (j = heightSize - 1; j > i; j--) {
                if (height[j] > height[right_highest]) {
                    right_highest = j;
                }
            }
        }
        lower = height[left_highest] > height[right_highest] ? height[right_highest] : height[left_highest];
        if (lower <= height[i])
            continue;
        water += lower - height[i];
    }
    return water;
}
