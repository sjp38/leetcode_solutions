static int valof(int *arr, int sz_arr)
{
    int i;
    int ret = 0;
    for (i = 1; i < sz_arr; i++)
        ret += i * arr[i];
    return ret;
}

int maxRotateFunction(int* A, int ASize){
    int maxval;
    int i;
    int *arr;
    arr = (int *)malloc(sizeof(int) * ASize * 2);
    memcpy(arr, A, sizeof(int) * ASize);
    memcpy(&arr[ASize], A, sizeof(int) * ASize);
    maxval = valof(arr, ASize);
    for (i = 1; i < ASize; i++, arr++) {
        if (valof(arr, ASize) > maxval)
            maxval = valof(arr, ASize);
    }
    return maxval;
}
