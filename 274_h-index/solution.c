int hIndex(int* citations, int citationsSize){
    int hidx = -1;
    int gt, lt, eq;
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
        if (gt + eq >= hidx)
            return hidx;
    }
    return 0;
}
