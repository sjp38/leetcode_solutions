int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    bool *has_trusts;
    bool *trusts_map;
    int *nr_trusts;
    bool is_judge;
    int i;

    has_trusts = (bool *)calloc(N, sizeof(bool));
    trusts_map = (bool *)calloc(N * N, sizeof(bool));
    nr_trusts = (int *)calloc(N, sizeof(int));
    for (i = 0; i < trustSize; i++) {
        // has_trusts[i] is true if i trusts anyone
        has_trusts[trust[i][0] - 1] = true;
        // trusts_map[i][j] is true if i trusts j
        if (!trusts_map[(trust[i][0] - 1) * N + trust[i][1] - 1]) {
            nr_trusts[trust[i][1] - 1]++;
            trusts_map[(trust[i][0] - 1) * N + trust[i][1] - 1] = true;
        }
    }
    for (i = 0; i < N; i++) {
        if (has_trusts[i])
            continue;
        if (nr_trusts[i] == N - 1)
            return i + 1;
    }
    return -1;
}
