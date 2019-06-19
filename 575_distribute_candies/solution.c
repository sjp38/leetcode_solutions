int intcmp(void *l, void *r) {
    return *(int *)l - *(int *)r;
}

int distributeCandies(int* candies, int candiesSize){
    bool exists[200001] = {false,};
    int nr_kinds = 0;
    int i;
    for (i = 0; i < candiesSize && nr_kinds < candiesSize / 2; i++) {
        if (!exists[candies[i] + 100000]) {
            exists[candies[i] + 100000] = true;
            nr_kinds++;
        }
    }
    return nr_kinds;
}
