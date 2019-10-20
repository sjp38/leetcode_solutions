bool isIsomorphic(char * s, char * t){
    char map[256] = {0,}; /* maps s to t */
    bool rmap[256] = {false,};
    for (;*s != '\0'; s++, t++) {
        if (map[*s] == '\0') {
            if (rmap[*t])
                return false;
            map[*s] = *t;
            rmap[*t] = true;
            continue;
        }
        if (map[*s] != *t)
            return false;
    }
    return true;
}
