char findTheDifference(char * s, char * t){
    int nr_letters[26] = {0,};
    char *c;
    int i;
    for (c = s; *c; c++)
        nr_letters[*c - 'a']++;
    for (c = t; *c; c++) {
        nr_letters[*c - 'a']--;
        if (nr_letters[*c - 'a'] < 0) {
            return *c;
        }
    }
    return NULL;
}
