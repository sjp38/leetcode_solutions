bool is_selfdividing(int nr)
{
    int digit;
    int i;
    for (i = nr; i; i = i / 10) {
        digit = i % 10;
        if (digit == 0 || nr % digit != 0)
            return false;
    }
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    int *ret, nr_nrs;
    int i;
    ret = (int *)malloc(sizeof(int) * right - left);
    nr_nrs = 0;
    for (i = left; i <= right; i++) {
        if (is_selfdividing(i))
            ret[nr_nrs++] = i;
    }
    *returnSize = nr_nrs;
    return ret;
}
