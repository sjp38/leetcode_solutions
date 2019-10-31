#define is_letter(c) (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))

char * reverseOnlyLetters(char * S) {
    char *ret;
    int i, j;
    ret = malloc(sizeof(char) * (strlen(S) + 1));
    for (i = 0, j = strlen(S) - 1; i < strlen(S); i++) {
        if (!is_letter(S[i])) {
            ret[i] = S[i];
        } else {
            while (!is_letter(S[j]))
                j--;
            ret[i] = S[j--];
        }
    }
    ret[strlen(S)] = '\0';
    return ret;
}
