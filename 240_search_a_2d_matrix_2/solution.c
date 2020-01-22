bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i, j, k, l;
    for (i = matrixRowSize - 1, j = matrixColSize - 1; i >= 0 && j >= 0; i--, j--) {
        if (matrix[i][j] < target)
            break;
    }
    i++, j++;
    if (i == matrixRowSize)
        return false;
    
    for (k = i; k < matrixRowSize; k++) {
        for (l = 0; l <= j; l++) {
            if (matrix[k][l] == target)
                return true;
        }
    }
    for (k = 0; k <= i; k++) {
        for (l = j; l < matrixColSize; l++) {
            if (matrix[k][l] == target)
                return true;
        }
    }
    return false;
}
