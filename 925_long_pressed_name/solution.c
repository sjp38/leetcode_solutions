

bool isLongPressedName(char * name, char * typed){
    char *n, *t, *prev_t;
    if (!*name && *typed)
        return false;
    for (n = name, t = typed, prev_t = typed; *n && *t; n++) {
        if (*n != *t) {
            while (prev_t != t && *prev_t == *t) {
                t++;
                prev_t++;
            }
        }
        if (*n != *t)
            return false;
        prev_t = t;
        t++;
    }
    if (*n || (n == name && *t))
        return false;
    while (*t) {
        if (*t != n[-1])
            return false;
        t++;
    }
    return true;
}
