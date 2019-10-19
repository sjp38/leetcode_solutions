bool isSubsequence(char * s, char * t){
    char *ct, *cs;
    for (ct = t, cs = s; *ct != '\0' && *cs != '\0'; ct++) {
        if (*ct == *cs)
            cs++;
    }
    if (*cs == '\0')
        return true;
    return false;
}
