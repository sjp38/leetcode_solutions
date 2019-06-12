char findTheDifference(char * s, char * t){
    int nr_letters_s[26] = {0,};
    int nr_letters_t[26] = {0,};
    char *c;
    int i;
    for (c = s; *c; c++)
        nr_letters_s[*c - 'a']++;
    for (c = t; *c; c++)
        nr_letters_t[*c - 'a']++;
    for (i = 0; i < 26; i++) {
        if (nr_letters_s[i] != nr_letters_t[i])
            return 'a' + i;
    }
    return NULL;
}
