typedef struct Trie {
    struct Trie *childs[26];
    bool is_end;
} Trie;

#define idxof(c) (c - 'a')

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *ret;
    ret = (Trie *)calloc(1, sizeof(Trie));
    return ret;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *node;
    for (; *word; word++) {
        if (obj->childs[*word - 'a'] == NULL) {
            node = (Trie *)calloc(1, sizeof(Trie));
            obj->childs[*word - 'a'] = node;
        }
        obj = obj->childs[*word - 'a'];
    }
    obj->is_end = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    for (; *word; word++) {
        if (obj->childs[idxof(*word)] == NULL)
            return false;
        obj = obj->childs[idxof(*word)];
    }
    if (!obj->is_end)
        return false;
    return true;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    for (; *prefix; prefix++) {
        if (obj->childs[idxof(*prefix)] == NULL)
            return false;
        obj = obj->childs[idxof(*prefix)];
    }
    return true;
}

void trieFree(Trie* obj) {
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
