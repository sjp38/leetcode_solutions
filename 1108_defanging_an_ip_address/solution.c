char * defangIPaddr(char * address){
    char *ret;
    char *c, *r;
    ret = (char *)malloc(sizeof(char) * (strlen(address) + 7));
    for (c = address, r = ret; *c; c++, r++) {
        if (*c == '.') {
            r[0] = '[';
            r[1] = '.';
            r[2] = ']';
            r += 2;
            continue;
        }
        *r = *c;
    }
    *r = '\0';
    return ret;
}
