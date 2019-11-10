int binaryGap(int N){
    int idx = 0;
    int last_one = -1;
    int max_dist;
    for (idx = 0, last_one = -1, max_dist = 0; N; idx++) {
        if (N % 2 == 0) {
            N /= 2;
            continue;
        }
        if (last_one != -1) {
            if (max_dist < idx - last_one)
                max_dist = idx - last_one;
        }
        last_one = idx;
        N /= 2;
    }
    return max_dist;
}
