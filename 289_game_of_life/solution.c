int **gboard;
int nr_rows;
int nr_cols;

static inline int count_lives(int row, int col) {
    int i, j;
    int ret = 0;

    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i < 0 || i >= nr_rows || j < 0 || j >= nr_cols)
                continue;
            if (i == row && j == col)
                continue;
            if (gboard[i][j] == 1)
                ret++;
        }
    }
    return ret;
}

static inline void update(int **updated, int row, int col) {
    int nr_lives, nr_deads;
    
    nr_lives = count_lives(row, col);
    updated[row][col] = 0;
    if (gboard[row][col] && (nr_lives == 2 || nr_lives == 3)) {
        updated[row][col] = 1;
        return;
    }
    if (gboard[row][col] == 0 && nr_lives == 3)
        updated[row][col] = 1;
}

/* boardSize: nr_rows, boardColSize: nr_cols */
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int **updated;
    int row, col;
    
    gboard = board;
    nr_rows = boardSize;
    nr_cols = *boardColSize;
    
    updated = (int **)malloc(sizeof(int *) * nr_rows);
    for (row = 0; row < nr_rows; row++)
        updated[row] = (int *)malloc(sizeof(int) * nr_cols);

    for (row = 0; row < nr_rows; row++) {
        for (col = 0; col < nr_cols; col++)
            update(updated, row, col);
    }
    
    for (row = 0; row < nr_rows; row++) {
        for (col = 0; col < nr_cols; col++)
            board[row][col] = updated[row][col];
        free(updated[row]);
    }
    free(updated);
}
