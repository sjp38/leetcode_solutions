#define is_reg_chr(c) \
    (c != ' ' && c != '!' && c != '?' && c != '\'' && \
     c != ',' && c != ';' && c != '.' && c != '\0')

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
    char *words[1000] = {0,}; /* strlen(paragraph) <= 1000 */
    char parag[1000];
    int word_freqs[1000] = {0,};
    char in_word = 0;
    char *word_start;
    char c;
    int i, j, idx_answer = -1;
    char is_ban_word = 0;
    char *ret;
    
    strcpy(parag, paragraph);
    for (i = 0; i < 1000; i++) {
        c = parag[i];
        
        if (!in_word && !is_reg_chr(c))
            continue;
        if (!in_word && is_reg_chr(c)) {
            word_start = &parag[i];
            in_word = 1;
            parag[i] = tolower(parag[i]);
            continue;
        }
        if (in_word && is_reg_chr(c)) {
            parag[i] = tolower(parag[i]);
            continue;
        }
        if (in_word && !is_reg_chr(c)) {
            in_word = 0;
            parag[i] = '\0';
            for (j = 0; j < bannedSize; j++) {
                if (!strcmp(word_start, banned[j])) {
                    is_ban_word = 1;
                    break;
                }
            }
            if (is_ban_word) {
                is_ban_word = 0;
                continue;
            }
 
            for (j = 0; j < 1000; j++) {
                if (words[j] == NULL) {
                    words[j] = word_start;
                    word_freqs[j] = 1;
                    break;
                }
                if (!strcmp(word_start, words[j])) {
                    word_freqs[j]++;
                    break;
                }
            }
            if (idx_answer == -1 || (word_freqs[idx_answer] < word_freqs[j]))
                idx_answer = j;
        }
	if (c == '\0')
		break;
    }

    for (i = 0; i < 1000 && words[i] != NULL; i++) {
	    printf("%s %d\n", words[i], word_freqs[i]);
    }

    ret = (char *)malloc(sizeof(char) * strlen(words[idx_answer]));
    strcpy(ret, words[idx_answer]);
    return ret;
}
