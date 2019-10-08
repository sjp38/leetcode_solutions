char * licenseKeyFormatting(char * S, int K){
    char *c, *ret, *ret2;
    int nr_c_in_group;
    int i, j;
    ret = (char *)malloc(sizeof(char) * (strlen(S) * 2 + 1));
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
    ret2 = (char *)malloc(sizeof(char) * (strlen(&ret[j + 1]) + 1));
    strcpy(ret2, &ret[j + 1]);
    free(ret);
    return ret2;
}
