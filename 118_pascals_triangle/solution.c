/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int **ret;
    int *colSz;
    int *row;
    int len_row;
    int i, j;
    
    ret = (int **)malloc(sizeof(int *) * numRows);
    colSz = (int *)malloc(sizeof(int) * numRows);
    for (i = 0; i < numRows; i++) {
        len_row = i + 1;
        row = (int *)malloc(sizeof(int) * len_row);
        for (j = 0; j < len_row; j++) {
            if (j == 0 || j == len_row - 1) {
                row[j] = 1;
                continue;
            }
            row[j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        ret[i] = row;
        colSz[i] = len_row;
    }
    *columnSizes = colSz;
    return ret;
}
