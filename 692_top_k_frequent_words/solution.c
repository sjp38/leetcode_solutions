struct frequency {
    int idx_word;
    int freq;
};

int wordcmp(const void *l, const void *r)
{
    return strcmp(*(char **)l, *(char **)r);
}

void new_freq(struct frequency *f, struct frequency *freqs, int nr_freqs)
{
    int i, j;
    if (f->freq <= freqs[nr_freqs - 1].freq)
        return;
    for (i = 0; i < nr_freqs; i++) {
        if (f->freq > freqs[i].freq) {
            for (j = nr_freqs - 2; j >= i; j--)
                freqs[j + 1] = freqs[j];
            freqs[i] = *f;
            return;
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    int i;
    struct frequency *freqs, f = {0,};
    char **ret;
    freqs = (struct frequency *)calloc(k, sizeof(struct frequency));
    qsort(words, wordsSize, sizeof(char *), wordcmp);
    for (i = 0; i < wordsSize; i++) {
        if (f.freq == 0) {
            f.idx_word = i;
            f.freq = 1;
        }
        if (i < wordsSize - 1 && !strcmp(words[i], words[i + 1])) {
            f.freq++;
            continue;
        } else {
            new_freq(&f, freqs, k);
            f.freq = 0;
        }
    }
    ret = (char **)malloc(sizeof(char *) * k);
    for (i = 0; i < k; i++) {
        ret[i] = words[freqs[i].idx_word];
    }
    free(freqs);
    *returnSize = k;
    return ret;
}
