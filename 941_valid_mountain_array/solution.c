bool validMountainArray(int* A, int ASize){
    bool increasing = true;
    int i;
    if (ASize < 3)
        return false;
    for (i = 1; i < ASize; i++) {
        if (A[i] == A[i - 1])
            return false;
        if (increasing && A[i] <= A[i - 1]) {
            if (i == 1)
                return false;
            increasing = false;
            continue;
        }
        if (!increasing && A[i] >= A[i - 1])
            return false;
    }
    if (increasing)
        return false;
    return true;
}
