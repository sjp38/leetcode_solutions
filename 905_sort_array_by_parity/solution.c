/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *evens;
    int *odds;
    int i, ie, io;
    evens = (int *)malloc(sizeof(int) * ASize);
    odds = (int *)malloc(sizeof(int) * ASize);
    for (i = 0, ie = 0, io = 0; i < ASize; i++) {
        if (A[i] % 2)
            odds[io++] = A[i];
        else
            evens[ie++] = A[i];
    }
    memcpy(&evens[ie], &odds[0], sizeof(int) * io);
    free(odds);
    *returnSize = ASize;
    return evens;
}
