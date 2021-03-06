bool do_search_matrix(int** matrix, int row_start, int row_end, int col_start, int col_end, int target)
{
    int i, j, k;
    for (i = row_end - 1, j = col_end - 1; i >= row_start && j >= col_start; i--, j--) {
        if (matrix[i][j] < target)
            break;
    }
    i++, j++;
    if (i == row_end || j == col_end)
        return false;
    
    if (i == row_end - 1) {
        for (k = col_start; k < j + 1; k++) {
            if (matrix[i][k] == target)
                return true;
        }
    } else if (do_search_matrix(matrix, i, row_end, col_start, j + 1, target)) {
        return true;
    }
    
    if (j == col_end - 1) {
        for (k = row_start; k < i + 1; k++) {
            if (matrix[k][j] == target)
                return true;
        }
    } else if (do_search_matrix(matrix, row_start, i + 1, j, col_end, target)) {
        return true;
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return do_search_matrix(matrix, 0, matrixRowSize, 0, matrixColSize, target);
}
