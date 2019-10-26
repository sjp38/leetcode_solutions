/*
1 -> 1
2 -> 2
...
9 -> 9
10 -> 1
11 -> 0
12 -> 1
13 -> 1
...

*/

static int digitof(int nr, int offset)
{
    int i;
    int base = 1;
    for (i = 0; i < offset; i++)
        base *= 10;
    return nr % (base * 10) / base;
}

int findNthDigit(int n){
    long n_start = 0;
    unsigned long max_n = 9;
    long nr_start = 0;
    unsigned long max_nr = 9;
    int digits = 1;
    while (max_n < n) {
        nr_start = max_nr + 1;
        max_nr = (max_nr + 1) * 10 - 1;
        digits++;
        n_start = max_n + 1;
        max_n += (max_nr - nr_start + 1) * digits;
    }
    int nr, offset;
    nr = nr_start + (n - n_start) / digits;
    offset = digits - (n - n_start) % digits - 1;
    return digitof(nr, offset);
}
