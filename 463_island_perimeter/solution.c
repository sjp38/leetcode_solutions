int **cells;
int nr_rows;
int nr_cols;

/* Returns 1 if the cell is water */
static inline char iswater(int row, int col) {
    if (row < 0 || row >= nr_rows || col < 0 || col >= nr_cols)
        return 1;
    if (cells[row][col] == 0)
        return 1;
    return 0;    
}

/* Returns perimeter of given ground cell */
static inline int perimeterof(int row, int col) {
    int ret = 0;

    /* check up, down, left and right */
    if (iswater(row - 1, col))
        ret += 1;
    if (iswater(row + 1, col))
        ret += 1;
    if (iswater(row, col - 1))
        ret += 1;
    if (iswater(row, col + 1))
        ret += 1;

    return ret;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i, j;
    int perim = 0;

    cells = grid;
    nr_rows = gridSize;
    nr_cols = *gridColSize;

    for (i = 0; i < nr_rows; i++) {
        for (j = 0; j < nr_cols; j++) {
            if (grid[i][j] == 0)
                continue;
            perim += perimeterof(i, j);
        }
    }

    return perim;
}
