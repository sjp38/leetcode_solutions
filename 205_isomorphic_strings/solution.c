bool isIsomorphic(char * s, char * t){
    char map[256] = {0,}; /* maps s to t */
    char rmap[256] = {0,};
    for (;*s != '\0'; s++, t++) {
        if (map[*s] == '\0') {
            if (rmap[*t] != '\0')
                return false;
            map[*s] = *t;
            rmap[*t] = *s;
            continue;
        }
        if (map[*s] != *t)
            return false;
    }
    return true;
}
