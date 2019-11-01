#define min(x, y) (x > y ? y : x)

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int *skyline[2];
    int i, j;
    int ret;
    for (i = 0; i < 2; i++)
        skyline[i] = (int *)calloc(gridSize, sizeof(int));
    /* top/bottom skyline */
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            if (skyline[0][i] < grid[j][i])
                skyline[0][i] = grid[j][i];
        }
    }
    /* left/right skyline */
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            if (skyline[1][i] < grid[i][j])
                skyline[1][i] = grid[i][j];
        }
    }
    ret = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            ret += min(skyline[0][i], skyline[1][j]) - grid[i][j];
        }
    }
    return ret;
}
