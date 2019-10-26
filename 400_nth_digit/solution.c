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
10 + n * 2 + 1 -> n

suppose reversely.
We try to know what number the n'th digits below.
the number increments one as n increases one, until 0-9
(0-9 -> 0-9)
the number increments one as n increases two, until 10-99
(10-99 -> 10-(10 + (99 - 10) * 2 + 1))
n = 10 + (x - 10) * 2
(x - 10) * 2 = n - 10
x - 10 = (n - 10) / 2
x = (n - 10) /2 + 10
the number increments one as n increases three, until 100-990,
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
