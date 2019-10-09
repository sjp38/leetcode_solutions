int strStr(char * haystack, char * needle){
    char *c;
    bool is_needle;
    int first_diff;
    int i, j, k;
    if (needle[0] == '\0')
        return 0;
    if (strlen(haystack) < strlen(needle))
        return -1;
    for (i = 0; i < strlen(needle); i++) {
        if (needle[i] != needle[0])
            break;
    }
    first_diff = i;
    for (i = 0; i < strlen(haystack) - strlen(needle) + 1; i++) {
        if (haystack[i] == needle[0]) {
            is_needle = true;
            for (j = 1; j < strlen(needle); j++) {
                if (haystack[i + j] != needle[j]) {
                    is_needle = false;
                    break;
                }
            }
            if (j == first_diff && haystack[i + j] == needle[0]) {
                for (k = i + j + 1; k < strlen(haystack) - strlen(needle) + 1; k++) {
                    if (haystack[k] == needle[0])
                        continue;
                    if (haystack[k] == needle[first_diff])
                        i = k - first_diff - 1;
                    break;
                }
            }
            if (is_needle)
                return i;
        }
    }
    return -1;
}
