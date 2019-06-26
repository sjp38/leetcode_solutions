int trap(int* height, int heightSize){
    int water = 0;
    int left_highest, right_highest, lower;
    int i, j;
    for (i = 1; i < heightSize - 1; i++) {
        left_highest = 0, right_highest = 0;
        for (j = 0; j < i; j++) {
            if (height[j] > left_highest)
                left_highest = height[j];
        }
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
