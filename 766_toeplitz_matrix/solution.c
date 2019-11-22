bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    for (j = 1; j < matrixSize; j++) {
        for (i = 1; i < matrixColSize[0]; i++) {
            if (matrix[j][i] != matrix[j - 1][i - 1])
                return false;
        }
    }
    return true;
}
