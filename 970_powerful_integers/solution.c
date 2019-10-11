int len = 0, cap = 64;
int *buf;

void append(int v) {
    int i;
    if (len + 1 >= cap) {
        cap *= 2;
        realloc(buf, sizeof(char) * cap);
    }
    buf[len++] = v;
}

int logof(int v, int base) {
    int ret = 0;
    if (base == 1)
        return 1;
    while (v) {
        ret++;
        v /= base;
    }
    return ret;
}

int cmp(void *l, void *r)
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
    if (buf != NULL) {
        free(buf);
        len = 0;
        cap = 64;
    }
    buf = (int *)malloc(sizeof(int) * cap);
    xbound = logof(bound, x);
    ybound = logof(bound, y);
    
    for (i = 0, xv = 1; i < xbound; i++) {
        for (j = 0, yv = 1; j < ybound; j++) {
            v = xv + yv;
            //printf("2**%d + 3**%d: %d\n", i, j, v);
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
