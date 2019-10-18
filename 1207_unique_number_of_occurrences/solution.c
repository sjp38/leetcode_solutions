int intcmp(const void *l, const void *r)
{
    return *(int *)l - *(int *)r;
}

bool uniqueOccurrences(int* arr, int arrSize){
    int i;
    int occurences[arrSize];
    int nr_occ = 0;
    int first_idx;
    if (arrSize < 2)
        return true;
    qsort(arr, arrSize, sizeof(int), intcmp);
    for (i = 1, first_idx = 0; i < arrSize; i++) {
        if (arr[i - 1] == arr[i])
            continue;
        occurences[nr_occ++] = i - first_idx;
        first_idx = i;
    }
    occurences[nr_occ++] = i - first_idx;
    qsort(occurences, nr_occ, sizeof(int), intcmp);
    for (i = 0; i < nr_occ - 1; i++)
        if (occurences[i] == occurences[i + 1])
            return false;
    return true;
}
