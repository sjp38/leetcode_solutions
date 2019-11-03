bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int left, mid, right;
    int row, col;
    if (matrixSize == 0 || matrixColSize[0] == 0)
        return false;
    left = 0;
    right = matrixSize * matrixColSize[0] - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        row = mid / matrixColSize[0];
        col = mid % matrixColSize[0];
        if (matrix[row][col] < target)
            left = mid + 1;
        else if (matrix[row][col] > target)
            right = mid - 1;
        else
            return true;
    }
    return false;
}
