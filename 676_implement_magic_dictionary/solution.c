typedef struct {
    char **words;
    int nr_words;
} MagicDictionary;

/** Initialize your data structure here. */

MagicDictionary* magicDictionaryCreate() {
    return (MagicDictionary *)malloc(sizeof(MagicDictionary));
}

/** Build a dictionary through a list of words */
void magicDictionaryBuildDict(MagicDictionary* obj, char ** dict, int dictSize) {
    obj->nr_words = dictSize;
    obj->words = dict;
}

bool is_it(char *a, char *b)
{
    int nr_diff;
    for(nr_diff = 0; *a && *b && nr_diff <= 1; a++, b++) {
        if (*a != *b)
            nr_diff++;
    }
    if (*a || *b || nr_diff != 1)
        return false;
    return true;
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
bool magicDictionarySearch(MagicDictionary* obj, char * word) {
    int i;
    for (i = 0; i < obj->nr_words; i++) {
        if (is_it(obj->words[i], word))
            return true;
    }
    return false;
}

void magicDictionaryFree(MagicDictionary* obj) {
    free(obj);
}

/**
 * Your MagicDictionary struct will be instantiated and called as such:
 * MagicDictionary* obj = magicDictionaryCreate();
 * magicDictionaryBuildDict(obj, dict, dictSize);
 
 * bool param_2 = magicDictionarySearch(obj, word);
 
 * magicDictionaryFree(obj);
*/
