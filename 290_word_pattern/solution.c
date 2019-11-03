bool wordPattern(char * pattern, char * str){
    char **map;
    char *c;
    int i;
    bool end = false;
    map = (char **)calloc(26, sizeof(char *));
    for (; *pattern; pattern++) {
        for (c = str; *c != ' ' && *c != '\0'; c++)
            ;
        if (*c == '\0')
            end = true;
        if (end && pattern[1] != '\0')
            return false;
        *c = '\0';
        if (map[*pattern - 'a'] == NULL) {
            for (i = 0; i < 26; i++) {
                if (map[i] != NULL &&
                    !strcmp(map[i], str))
                    return false;
            }
            map[*pattern - 'a'] = str;
        } else {
            if (strcmp(map[*pattern - 'a'], str))
                return false;
        }
        str = c + 1;
    }
    if (!end)
        return false;
    return true;
}
