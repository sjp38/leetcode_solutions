int strStr(char * haystack, char * needle){
    int i, j;
    if (needle[0] == '\0')
        return 0;
    for (i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            for (j = 1; needle[j] != '\0'; j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (needle[j] == '\0')
                return i;
            if (haystack[i + j] == '\0')
                break;
        }
    }
    return -1;
}
