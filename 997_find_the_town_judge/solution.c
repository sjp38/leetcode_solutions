int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    bool *has_trusts;
    bool *trusts_map;
    bool is_judge;
    int i, j;

    has_trusts = (bool *)calloc(N, sizeof(bool));
    trusts_map = (bool *)calloc(N * N, sizeof(bool));
    for (i = 0; i < trustSize; i++) {
        // has_trusts[i] is true if i trusts anyone
        has_trusts[trust[i][0] - 1] = true;
        // trusts_map[i][j] is true if i trusts j
        trusts_map[(trust[i][0] - 1) * N + trust[i][1] - 1] = true;
    }
    for (i = 0; i < N; i++) {
        if (has_trusts[i])
            continue;
        is_judge = true;
        for (j = 0; j < N; j++) {
            if (!trusts_map[j * N + i] && i != j) {
                is_judge = false;
                break;
            }
        }
        if (is_judge)
            return i + 1;
    }
    return -1;
}
