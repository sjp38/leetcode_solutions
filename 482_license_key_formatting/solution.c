char * licenseKeyFormatting(char * S, int K){
    char *c, *ret;
    int nr_c_in_group;
    int i, j;
    ret = malloc(sizeof(char) * (strlen(S) * 2 + 1));
    j = strlen(S) * 2;
    ret[j--] = '\0';
    nr_c_in_group = 0;
    for (i = strlen(S) - 1; i >= 0; i--) {
        if (S[i] == '-')
            continue;
        if (nr_c_in_group  == K) {
            ret[j--] = '-';
            i++;
            nr_c_in_group = 0;
            continue;
        }
        if ('a' <= S[i] && S[i] <= 'z')
            S[i] = 'A' + (S[i] - 'a');
        ret[j--] = S[i];
        nr_c_in_group++;
    }
    return &ret[j + 1];
}
