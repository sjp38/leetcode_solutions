int trap(int* height, int heightSize){
    int water = 0;
    int left_highest, right_highest, lower;
    int i, j;
    if (heightSize <= 2)
        return 0;
    left_highest = height[0];
    for (i = 1; i < heightSize - 1; i++) {
        right_highest = 0;
        if (height[i - 1] > left_highest)
            left_highest = height[i - 1];
        for (j = heightSize - 1; j > i; j--) {
            if (height[j] > right_highest)
                right_highest = height[j];
        }
        lower = left_highest > right_highest ? right_highest : left_highest;
        if (lower <= height[i])
            continue;
        water += lower - height[i];
    }
    return water;
}
