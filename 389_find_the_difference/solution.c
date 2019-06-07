int cmp(char *a, char *b) {
    return *a - *b;
}

char findTheDifference(char * s, char * t){
    int i;
    qsort(s, strlen(s), sizeof(char), cmp);
    qsort(t, strlen(t), sizeof(char), cmp);
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != t[i])
            return t[i];
    }
    return t[strlen(t) - 1];
}
