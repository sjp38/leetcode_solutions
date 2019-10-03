/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** removeComments(char ** source, int sourceSize, int* returnSize){
    char *line, *rline = NULL, **rlines;
    int idx_rline = 0;
    bool in_block_comment = false;
    int i, j;
    rlines = (char **)malloc(sizeof(char *) * sourceSize);
    *returnSize = 0;
    for (i = 0; i < sourceSize; i++) {
        line = source[i];
        if (rline == NULL)
            rline = (char *)malloc(sizeof(char) * 81);
        for (j = 0; j < strlen(line); j++) {
            if (!in_block_comment) {
                if (strncmp(&line[j], "//", 2) == 0) {
                    break;
                }
                if (strncmp(&line[j], "/*", 2) == 0) {
                    in_block_comment = true;
                    j++;
                    continue;
                }
            } else {
                if (strncmp(&line[j], "*/", 2) == 0) {
                    in_block_comment = false;
                    j++;
                    continue;
                }
                continue;
            }
            rline[idx_rline++] = line[j];
        }
        if (idx_rline == 0)
            continue;
        if (in_block_comment) {
            rline = realloc(rline, sizeof(char) * (idx_rline + 81));
            continue;
        }
        rline[idx_rline] = '\0';
        idx_rline = 0;
        rlines[(*returnSize)++] = rline;
        rline = NULL;
    }
    return rlines;
}
