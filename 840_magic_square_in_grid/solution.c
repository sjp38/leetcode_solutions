bool is_magic(int **grid, int row, int col)
{
    bool nums[9] = {0,};
    int sum, last_sum;
    int i, j;
    for (i = row; i < row + 3; i++) {
        for (j = col, sum = 0; j < col + 3; j++) {
            if (grid[i][j] < 1 || grid[i][j] > 9)
                return false;
            if (nums[grid[i][j] - 1])
                return false;
            nums[grid[i][j] - 1] = true;
            sum += grid[i][j];
        }
        if (i == row)
            last_sum = sum;
        if (sum != last_sum) return false;
    }
    for (j = col; j < col + 3; j++) {
        for (i = row, sum = 0; i < row + 3; i++) {
            sum += grid[i][j];
        }
        if (sum != last_sum) return false;
    }
    for (i = 0, sum = 0; i < 3; i++)
        sum += grid[row + i][col + i];
    if (sum != last_sum) return false;
    for (i = 0, sum = 0; i < 3; i++)
        sum += grid[row - i + 2][col + i];
    if (sum != last_sum) return false;
    return true;
}

int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize){
    int i, j;
    int rc = 0;
    for (i = 0; i < gridSize - 2; i++) {
        for (j = 0; j < gridColSize[0] - 2; j++) {
            if (is_magic(grid, i, j))
                rc++;
        }
    }
    return rc;
}
