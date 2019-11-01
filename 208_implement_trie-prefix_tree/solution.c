typedef struct Trie {
    struct Trie *childs[26];
    bool is_end;
} Trie;

#define childof(node, c) (node->childs[c - 'a'])

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
        if (!childof(obj, *word)) {
            node = (Trie *)calloc(1, sizeof(Trie));
            childof(obj, *word) = node;
        }
        obj = childof(obj, *word);
    }
    obj->is_end = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    for (; *word; word++) {
        if (!childof(obj, *word))
            return false;
        obj = childof(obj, *word);
    }
    if (!obj->is_end)
        return false;
    return true;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    for (; *prefix; prefix++) {
        if (!childof(obj, *prefix))
            return false;
        obj = childof(obj, *prefix);
    }
    return true;
}

void trieFree(Trie* obj) {
    int i;
    for (i = 0; i < 26; i++) {
        if (obj->childs[i])
            trieFree(obj->childs[i]);
    }
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
