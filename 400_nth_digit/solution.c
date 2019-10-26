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

int digitof(int nr, int offset)
{
    int i;
    int base = 1;
    for (i = 0; i < offset; i++)
        base *= 10;
    return nr % (base * 10) / base;
}

int findNthDigit(int n){
    long prev_max_n = -1;
    unsigned long max_n = 9;
    long prev_max_nr = -1;
    unsigned long max_nr = 9;
    int digits = 1;
    while (max_n < n) {
        prev_max_nr = max_nr;
        max_nr = (max_nr + 1) * 10 - 1;
        digits++;
        prev_max_n = max_n;
        max_n += (max_nr - prev_max_nr) * digits;
        //printf("%u %u\n", prev_max_nr, max_nr);
    }
    int nr, offset;
    nr = prev_max_nr + 1 + (n - prev_max_n - 1) / digits;
    //printf("prev_max_n: %d, max_n: %u, prev_max_nr: %d, max_nr: %lu, digits: %d, nr: %d\n", prev_max_n, max_n, prev_max_nr, max_nr, digits, nr);
    offset = (n - prev_max_n - 1) % digits;
    offset = digits - offset - 1;
    return digitof(nr, offset);
}
