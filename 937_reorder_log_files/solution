#define isdigit(x) (x >= '0' && x <= '9')

int logcmp(void *l, void *r) {
    char *ll, *rr;
    int ret;
    for (ll = *(char **)l; *ll != NULL; ll++) {
        if (*ll == ' ') {
            ll++;
            break;
        }
    }
    for (rr = *(char **)r; *rr != NULL; rr++) {
        if (*rr == ' ') {
            rr++;
            break;
        }
    }
    if (isdigit(*ll) && !isdigit(*rr))
        return 1;
    else if (!isdigit(*ll) && isdigit(*rr))
        return -1;
    else if (isdigit(*ll) && isdigit(*rr))
        return 0;
    ret = strcmp(ll, rr);
    if (ret == 0)
        return strcmp(*(char **)l, *(char **)r);
    return ret;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    char **sorted;
    sorted = (char **)malloc(sizeof(char *) * logsSize);
    memcpy(sorted, logs, sizeof(char *) * logsSize);
    qsort(sorted, logsSize, sizeof(char *), logcmp);
    *returnSize = logsSize;
    return sorted;
}
