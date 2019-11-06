char * toLowerCase(char * str){
    char *c;
    for (c = str; *c; c++) {
        if ('A' <= *c && *c <= 'Z')
            *c = 'a' + *c - 'A';
    }
    return str;
}
