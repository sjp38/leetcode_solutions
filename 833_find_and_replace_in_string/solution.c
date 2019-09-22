int *idxs;

int idxcmp(const void *l, const void *r)
{
    int il, ir;
    il = *(int *)l;
    ir = *(int *)r;
    return idxs[il] - idxs[ir];
}

char * findReplaceString(char * S, int* indexes, int indexesSize, char ** sources, int sourcesSize, char ** targets, int targetsSize){
    char *src, *target, *ret;
    int *todos, nr_todos, idx, todo;
    bool matched;
    size_t sz_new_s, rcursor, scursor;
    int i, j;
    
    todos = (int *)malloc(sizeof(int) * sourcesSize);
    nr_todos = 0;
    sz_new_s = strlen(S);
    for (i = 0; i < sourcesSize; i++) {
        src = sources[i];
        idx = indexes[i];
        if (idx + strlen(src) > strlen(S))
            continue;
        matched = true;
        for (j = 0; j < strlen(src); j++) {
            if (S[idx + j] != src[j]) {
                matched = false;
                break;
            }
        }
        if (matched) {
            todos[nr_todos++] = i;
            sz_new_s += strlen(targets[i]) - strlen(sources[i]);
        }
    }
    idxs = indexes;
    qsort(todos, nr_todos, sizeof(int), idxcmp);
    
    ret = (char *)malloc(sizeof(char) * (sz_new_s + 1));
    rcursor = scursor = 0;
    for (i = 0; i < nr_todos; i++) {
        todo = todos[i];
        idx = indexes[todo];
        src = sources[todo];
        target = targets[todo];
        strncpy(&ret[rcursor], &S[scursor], idx - scursor);
        strcpy(&ret[rcursor + idx - scursor], target);
        rcursor += idx - scursor + strlen(target);
        scursor += idx - scursor + strlen(src);
    }
    strcpy(&ret[rcursor], &S[scursor]);
    return ret;
}
