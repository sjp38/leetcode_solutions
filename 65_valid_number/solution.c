static char *strip(char *s)
{
    int i;
    char *ret;
    for (ret = s, i = 0; i < strlen(s); i++) {
        if (s[i] == ' ')
            ret = &s[i + 1];
        else
            break;
    }
    for (i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == ' ')
            s[i] = '\0';
        else
            break;
    }
    return ret;
}

static bool check_str(char *s, int idx_e)
{
    int i, idx_dot = -1;
    char c;
    if (idx_e == -1)
        idx_e = strlen(s);
    else if (idx_e == strlen(s) - 1)
        return false;
    
    if (s[0] == '-' || s[0] == '+') {
        s = &s[1];
        idx_e--;
    }
    if (idx_e == 0)
        return false;
    
    for (i = 0; i < idx_e; i++) {
        c = s[i];
        if (c == '.' && idx_dot == -1) {
            idx_dot = i;
            if (idx_dot == 0 && idx_dot + 1 == idx_e)
                return false;
            continue;
        }
        if (c < '0' || c > '9')
            return false;
    }
    
    for (i = idx_e + 1; i < strlen(s); i++) {
        c = s[i];
        if (c == '-' || c == '+' && i == idx_e + 1) {
            if (i == strlen(s) - 1)
                return false;
            continue;
        }
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}

bool isNumber(char * s){
    int i;
    int idx_e = -1;
    s = strip(s);
    for (i = 0; i <strlen(s); i++) {
        if (s[i] == 'e') {
            idx_e = i;
            break;
        }
    }
    return check_str(s, idx_e);
}
