static inline void cnt_chr(char *word, int *ret)
{
    int i;
    for (i = 0; i < strlen(word); i++)
        ret[word[i] - 'a']++;
}

int countCharacters(char ** words, int wordsSize, char * chars){
    int nr_c_word[26], nr_c_chrs[26] = {0,}, nr_c_chrs2[26];
    int i, j, ret = 0;
    bool is_good;
    cnt_chr(chars, nr_c_chrs);
    for (i = 0; i < wordsSize; i++) {
        for (j = 0; j < 26; j++) {
            nr_c_chrs2[j] = nr_c_chrs[j];
            nr_c_word[j] = 0;
        }
        for (is_good = true, j = 0; j < strlen(words[i]); j++) {
            nr_c_chrs2[words[i][j] - 'a']--;
            if (nr_c_chrs2[words[i][j] - 'a'] < 0) {
                is_good = false;
                break;
            }
        }
        if (!is_good)
            continue;
        ret += strlen(words[i]);
    }
    return ret;
}
