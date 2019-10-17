typedef struct {
    char **words;
    int nr_words;
    int cap;
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    WordDictionary *ret = (WordDictionary *)malloc(sizeof(WordDictionary));
    ret->cap = 100;
    ret->words = (char **)malloc(sizeof(char *) * ret->cap);
    ret->nr_words = 0;
    return ret;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    if (obj->nr_words == obj->cap) {
        obj->cap *= 2;
        obj->words = (char **)realloc(obj->words, sizeof(char *) * obj->cap);
    }
    obj->words[obj->nr_words++] = word;
}

int word_cmp(char *l, char *r)
{
    char *cl, *cr;
    for (cl = l, cr = r; *cl != '\0' && *cr != '\0'; cl++, cr++) {
        if (*cl != *cr && *cr != '.')
            return 1;
    }
    if (*cl == '\0' && *cr == '\0')
        return 0;
    return 1;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    int i;
    for (i = 0; i < obj->nr_words; i++) {
        if (!word_cmp(obj->words[i], word))
            return true;
    }
    return false;
}

void wordDictionaryFree(WordDictionary* obj) {
    free(obj->words);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
