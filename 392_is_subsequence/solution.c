bool isSubsequence(char * s, char * t){
    for (; *t != '\0' && *s != '\0'; t++) {
        if (*t == *s)
            s++;
    }
    if (*s == '\0')
        return true;
    return false;
}
