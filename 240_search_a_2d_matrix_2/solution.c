bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i, j, k, l;
    for (i = matrixRowSize - 1, j = matrixColSize - 1; i >= 0 && j >= 0; i--, j--) {
        if (matrix[i][j] < target)
            break;
    }
    if (i == matrixRowSize - 1)
        return false;
    for (k = i + 1; k < matrixRowSize; k++) {
        for (l = 0; l <= j + 1; l++) {
            if (matrix[k][l] == target)
                return true;
        }
    }
    for (k = 0; k <= i + 1; k++) {
        for (l = j + 1; l < matrixColSize; l++) {
            if (matrix[k][l] == target)
                return true;
        }
    }
    return false;
}
