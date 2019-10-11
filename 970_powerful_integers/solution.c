int len, cap;
int *buf;

static void append(int v) {
    if (len == cap) {
        cap *= 2;
        realloc(buf, sizeof(char) * cap);
    }
    buf[len++] = v;
}

static int logof(int v, int base) {
    int ret = 0;
    if (base == 1)
        return 1;
    for (ret = 0; v; v /= base, ret++)
        ;
    return ret;
}

static int cmp(void *l, void *r)
{
    return *(int *)l - *(int *)r;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize) {
    int xbound, ybound, xv, yv, v;
    int *ret;
    int i, j;
    if (buf != NULL)
        free(buf);
    len = 0;
    cap = 64;
    buf = (int *)malloc(sizeof(int) * cap);
    xbound = logof(bound, x);
    ybound = logof(bound, y);
    
    for (i = 0, xv = 1; i < xbound; i++) {
        for (j = 0, yv = 1; j < ybound; j++) {
            v = xv + yv;
            if (v <= bound)
                append(v);
            yv *= y;
        }
        xv *= x;
    }
    ret = (int *)malloc(sizeof(int) * len);
    *returnSize = len;
    qsort(buf, len, sizeof(int), cmp);
    for (i = 0, j = 0; i < len; i++) {
        if (i > 0 && buf[i] == buf[i - 1]) {
            *returnSize -= 1;
            continue;
        }
        ret[j++] = buf[i];
    }
    return ret;
}
