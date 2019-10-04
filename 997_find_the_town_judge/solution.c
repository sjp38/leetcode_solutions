int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    bool *has_trusts;
    bool *trusts_map;
    int *nr_trusts;
    int truster, trustee;
    int i;

    has_trusts = (bool *)calloc(N, sizeof(bool));
    trusts_map = (bool *)calloc(N * N, sizeof(bool));
    nr_trusts = (int *)calloc(N, sizeof(int));
    for (i = 0; i < trustSize; i++) {
        truster = trust[i][0] - 1;
        trustee = trust[i][1] - 1;
        has_trusts[truster] = true;
        if (!trusts_map[truster * N + trustee]) {
            nr_trusts[trustee]++;
            trusts_map[truster * N + trustee] = true;
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
