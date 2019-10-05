int hIndex(int* citations, int citationsSize){
    int hidx = -1;
    int gt, lt, eq, eq_in_h;
    int i;
    for (i = 0; i < citationsSize; i++) {
        if (hidx < citations[i])
            hidx = citations[i];
    }
    if (hidx > citationsSize)
        hidx = citationsSize;
    for (;hidx >= 0; hidx--) {
        for (i = 0, gt = 0, lt = 0, eq = 0;
             i < citationsSize; i++) {
            if (citations[i] > hidx)
                gt++;
            else if (citations[i] < hidx)
                lt++;
            else
                eq++;
        }
        eq_in_h = gt + eq - hidx;
        if (eq_in_h >= 0 &&
            lt + eq_in_h == citationsSize - hidx)
            return hidx;
    }
    return 0;
}
