/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char * S, char C, int* returnSize){
    int leftidx = -1, rightidx = -1;
    char *c;
    int *ret;
    int i, last_idx;
    ret = (int *)malloc(sizeof(int) * strlen(S));
    *returnSize= strlen(S);
    for (c = S; *c; c++) {
        if (*c == C) {
            printf("%d\n", c - S);
            if (leftidx == -1) {
                leftidx = c - S;
                for (i = 0; i <= leftidx; i++)
                    ret[i] = leftidx - i;
                last_idx = leftidx;
            } else {
                if (rightidx != -1)
                    leftidx = rightidx;
                rightidx = c - S;
                for (i = last_idx + 1; i <= (leftidx + rightidx) / 2; i++) {
                    ret[i] = i - leftidx;
                }
                for (i = (leftidx + rightidx) / 2 + 1; i <= rightidx; i++) {
                    ret[i] = rightidx - i;
                }
                last_idx = rightidx;
            }
        }
    }
    if (rightidx == -1)
        rightidx = leftidx;
    for (i = last_idx + 1; i < c - S; i++) {
        ret[i] = i - rightidx;
    }
    return ret;
}
