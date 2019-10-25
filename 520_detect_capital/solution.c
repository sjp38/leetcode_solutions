#define is_uppercase(c) ('A' <= c && c <= 'Z')

bool detectCapitalUse(char * word){
    char *c;
    int nr_uppercases = 0;
    for (c = word + 1; *c; c++) {
        if (is_uppercase(*c))
            nr_uppercases++;
    }
    if (is_uppercase(*word)) {
        if ((c - word - 1) == nr_uppercases || nr_uppercases == 0)
            return true;
    } else if (nr_uppercases == 0)
        return true;
    return false;
}
