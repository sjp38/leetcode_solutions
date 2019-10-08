char * licenseKeyFormatting(char * S, int K){
    char *c, *ret;
    int nr_dashes = 0;
    int len_chr;
    int len_first_group;
    int len_ret;
    int i, j;
    for (i = 0; i < strlen(S); i++) {
        c = &S[i];
        if (*c >= 'a' && *c <= 'z')
            *c = 'A' + (*c - 'a');
        else if (*c == '-')
            nr_dashes++;
    }
    len_chr = strlen(S) - nr_dashes;
    len_first_group = len_chr % K;
    if (len_first_group == 0)
        len_first_group = K;
    len_ret = len_chr + len_chr / K - (len_first_group == K ? 1 : 0);
    ret = (char *)malloc(sizeof(char) * (len_ret + 1));
    for (i = 0, j = 0; i < strlen(S); i++) {
        c = &S[i];
        if (*c == '-')
            continue;
        if (j != 0 && 
            ((j == len_first_group) ||
            ((j - len_first_group) % (K + 1) == 0))) {
            ret[j++] = '-';
            i--;
            continue;
        }
        ret[j++] = S[i];
    }
    ret[j] = '\0';
    return ret;
}
