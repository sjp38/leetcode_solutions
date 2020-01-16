/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *ret;
    int i, j, max;
    
    ret = (int *)calloc(TSize, sizeof(int));
    *returnSize = TSize;
    
    max = T[0];
    for (i = 0; i < TSize; i++) {
        if (max < T[i])
            max = T[i];
    }
    
    for (i = 0; i < TSize - 1; i++) {
        if (T[i] == max) {
            ret[i] = 0;
            continue;
        }
        for (j = i + 1; j < TSize; j++) {
            if (T[j] > T[i]) {
                ret[i] = j - i;
                break;
            }
        }
    }
    return ret;
}
