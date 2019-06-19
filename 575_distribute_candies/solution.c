int intcmp(void *l, void *r) {
    return *(int *)l - *(int *)r;
}

int distributeCandies(int* candies, int candiesSize){
    int nr_kinds = 0, last_kind;
    int i;
    qsort(candies, candiesSize, sizeof(int), intcmp);
    for (i = 0; i < candiesSize; i++) {
        if (nr_kinds == 0) {
            nr_kinds++;
            last_kind = candies[i];
            continue;
        }
        if (candies[i] != last_kind) {
            nr_kinds++;
            last_kind = candies[i];
        }
    }
    if (nr_kinds > candiesSize / 2)
        return candiesSize / 2;
    return nr_kinds;
}
