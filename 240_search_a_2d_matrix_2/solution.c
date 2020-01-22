bool do_slow_search(int** matrix, int row_start, int row_end, int col_start, int col_end, int target)
{
    int i, j;
    for (i = row_start; i < row_end; i++) {
        for (j = col_start; j < col_end; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

bool do_search_matrix(int** matrix, int row_start, int row_end, int col_start, int col_end, int target)
{
    int i, j;
    for (i = row_end - 1, j = col_end - 1; i >= row_start && j >= col_start; i--, j--) {
        if (matrix[i][j] < target)
            break;
    }
    i++, j++;
    if (i == row_end)
        return false;
    
    if (i == row_end - 1) {
        if (do_slow_search(matrix, i, row_end, col_start, j + 1, target))
            return true;
    } else if (do_search_matrix(matrix, i, row_end, col_start, j + 1, target)) {
        return true;
    }
    
    if (j == col_end - 1) {
        if (do_slow_search(matrix, row_start, i + 1, j, col_end, target))
            return true;
    } else if (do_search_matrix(matrix, row_start, i + 1, j, col_end, target)) {
        return true;
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return do_search_matrix(matrix, 0, matrixRowSize, 0, matrixColSize, target);
}
