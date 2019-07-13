/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** wordSubsets(char ** A, int ASize, char ** B, int BSize, int* returnSize){
    int max_counts[26] = {0,};
    int local_counts[26] = {0,};
    char *s;
    int idx;
    int i, j, k;
    char **ret;
    int nr_rets = 0;
    bool is_universal;
    
    for (i = 0; i < BSize; i++) {
        s = B[i];
        for (k = 0; k < 26; k++)
            local_counts[k] = 0;
        for (j = 0; j < strlen(s); j++) {
            idx = s[j] - 'a';
            local_counts[idx]++;
            if (local_counts[idx] > max_counts[idx])
                max_counts[idx] = local_counts[idx];
        }
    }
    ret = (char **)malloc(sizeof(char *) * ASize);
    nr_rets = 0;
    for (i = 0; i < ASize; i++) {
        s = A[i];
        for (k = 0; k < 26; k++)
            local_counts[k] = max_counts[k];
        for (j = 0; j < strlen(s); j++) {
            idx = s[j] - 'a';
            local_counts[idx]--;
        }
        is_universal = true;
        for (j = 0; j < 26; j++) {
            if (local_counts[j] > 0) {
                is_universal = false;
                break;
            }
        }
        
        if (!is_universal)
            continue;
        ret[nr_rets++] = s;
    }
    *returnSize = nr_rets;
    return ret;
}
