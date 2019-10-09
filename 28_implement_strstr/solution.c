int strStr(char * haystack, char * needle){
    char *c;
    bool is_needle;
    int i, j;
    if (needle[0] == '\0')
        return 0;
    if (strlen(haystack) < strlen(needle))
        return -1;
    for (i = 0; i < strlen(haystack) - strlen(needle) + 1; i++) {
        if (haystack[i] == needle[0]) {
            is_needle = true;
            for (j = 1; j < strlen(needle); j++) {
                if (haystack[i + j] != needle[j]) {
                    is_needle = false;
                    break;
                }
            }
            if (is_needle)
                return i;
        }
    }
    return -1;
}
