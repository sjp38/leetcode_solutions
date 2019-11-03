bool wordPattern(char * pattern, char * str){
    char **map;
    char *c;
    int i;
    map = (char **)calloc(26, sizeof(char *));
    for (; *pattern && *str; pattern++) {
        for (c = str; *c != ' ' && *c != '\0'; c++)
            ;
        if (*c == '\0')
            c--;
        else
            *c = '\0';
        if (map[*pattern - 'a'] == NULL) {
            for (i = 0; i < 26; i++) {
                if (map[i] && !strcmp(map[i], str))
                    return false;
            }
            map[*pattern - 'a'] = str;
        } else {
            if (strcmp(map[*pattern - 'a'], str))
                return false;
        }
        str = c + 1;
    }
    if (*str || *pattern)
        return false;
    return true;
}
