void cnt_chr(char *word, int *ret)
{
    int i;
    for (i = 0; i < strlen(word); i++)
        ret[word[i] - 'a']++;
}

int countCharacters(char ** words, int wordsSize, char * chars){
    int nr_c_word[26], nr_c_chrs[26] = {0,};
    int i, j, ret = 0;
    bool is_good;
    cnt_chr(chars, nr_c_chrs);
    for (i = 0; i < wordsSize; i++) {
        memset(nr_c_word, 0, sizeof(int) * 26);
        cnt_chr(words[i], nr_c_word);
        for (j = 0, is_good = true; j < 26; j++) {
            if (nr_c_chrs[j] < nr_c_word[j]) {
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
