int compare(const void *v1, const void *v2) {
    return *(int *)v1 - *(int *)v2;
}

int repeatedNTimes(int* A, int ASize) {
    int i, j;
    
    for (i = 0; i < ASize; i++) {
        for (j = i + 1; j < i + 4 && j < ASize; j++) {
            if (A[i] == A[j])
                return A[i];

        }
    }
    return -1;
}
