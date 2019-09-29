char * removeDuplicates(char * S){
    bool *removed;
    int len_S;
    int i, last_chr;
    bool found_dup;
    char *ret;
    int len_ret;
    len_S = strlen(S);
    len_ret = len_S + 1;
    removed = (bool *)calloc(len_S, sizeof(bool));
    do {
        found_dup = false;
        last_chr = -1;
        for (i = 0; i < len_S; i++) {
            if (removed[i])
                continue;
            if (last_chr == -1) {
                last_chr = i;
                continue;   
            }
            if (S[last_chr] == S[i]) {
                removed[last_chr] = removed[i] = true;
                len_ret -= 2;
                found_dup = true;
                last_chr = -1;
            } else {
                last_chr = i;
            }
        }
    } while (found_dup);
    
    ret = (char *)malloc(sizeof(char) * len_ret);
    for (i = 0, last_chr = 0; i < len_S; i++) {
        if (!removed[i])
            ret[last_chr++] = S[i];
    }
    ret[last_chr] = '\0';
    return ret;
}
