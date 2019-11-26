bool isMonotonic(int* A, int ASize){
    int i;
    bool increased = false, decreased = false;
    for (i = 1; i < ASize; i++) {
        if (A[i] > A[i-1])
            increased = true;
        else if (A[i] < A[i - 1])
            decreased = true;
        if (increased && decreased)
            return false;
    }
    return true;
}
