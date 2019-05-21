int maxArea(int* height, int heightSize){
    int i, j;
    int max_size = 0, w, h;
    
    for (i = 0, j = heightSize - 1; i < j; ) {
        w = i > j ? i - j : j - i;
        h = height[i] <= height[j] ? height[i] : height[j];
        if (w * h > max_size)
            max_size = w * h;
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return max_size;
}
