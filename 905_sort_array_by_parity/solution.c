/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *ret;
    int i, io;
    ret = (int *)malloc(sizeof(int) * ASize);
    for (i = 0, io = ASize - 1; i < ASize; i++) {
        if (A[i] % 2)
            ret[io--] = A[i];
        else
            ret[i - (ASize - 1 - io)] = A[i];
    }
    *returnSize = ASize;
    return ret;
}
