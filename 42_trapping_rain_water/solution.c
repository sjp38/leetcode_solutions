int trap(int* height, int heightSize){
    int water = 0;
    int left_highest, right_highest, lower;
    int right_highest_x = 1;
    int i, j;
    if (heightSize <= 2)
        return 0;
    left_highest = height[0];
    right_highest = height[right_highest_x];
    for (i = 1; i < heightSize - 1; i++) {
        if (height[i - 1] > left_highest)
            left_highest = height[i - 1];
        if (i >= right_highest_x) {
            right_highest = 0;
            for (j = heightSize - 1; j > i; j--) {
                if (height[j] > right_highest) {
                    right_highest = height[j];
                    right_highest_x = j;
                }
            }
        }
        lower = left_highest > right_highest ? right_highest : left_highest;
        if (lower <= height[i])
            continue;
        water += lower - height[i];
    }
    return water;
}
