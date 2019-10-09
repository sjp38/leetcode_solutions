int strStr(char * haystack, char * needle){
    bool is_needle;
    int i, j;
    if (needle[0] == '\0')
        return 0;
    for (i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            is_needle = true;
            for (j = 1; needle[j] != '\0'; j++) {
                if (haystack[i + j] != needle[j]) {
                    is_needle = false;
                    break;
                }
            }
            if (is_needle)
                return i;
            if (haystack[i + j] == '\0')
                break;
        }
    }
    return -1;
}
