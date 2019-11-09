#define nrof(c) (nr_chrs[c - 'a'])

int maxNumberOfBalloons(char * text){
    int nr_chrs[26] = {0,};
    char *c;
    int nr_balloons = 0;
    for (c = text; *c; c++) {
        nr_chrs[*c - 'a']++;
        if (nrof('b') && nrof('a') && nrof('l') >= 2 && nrof('o') >= 2 && nrof('n')) {
            nr_balloons++;
            nrof('b') -= 1;
            nrof('a') -= 1;
            nrof('l') -= 2;
            nrof('o') -= 2;
            nrof('n') -= 1;
        }
    }
    return nr_balloons;
}
