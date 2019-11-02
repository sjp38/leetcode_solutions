#define right   1
#define left    2
#define up      3
#define down    4

static int **matrix;
static int nr_cols, nr_rows;

static bool *visited;
static int *ret;
static int idx;
static int col, row;
static int direction;

/* Returns true if next traverse possible */
static bool ensure_direction(void)
{
    if (col == nr_cols || col < 0 ||
        row == nr_rows || row < 0 ||
        visited[row * nr_cols + col]) {
        switch (direction) {
            case right:
                col--;
                direction = down;
                row++;
                break;
            case left:
                col++;
                direction = up;
                row--;
                break;
            case up:
                row++;
                direction = right;
                col++;
                break;
            case down:
                row--;
                direction = left;
                col--;
                break;
        }
    }
    return !(col == nr_cols || col < 0 ||
        row == nr_rows || row < 0 ||
        visited[row * nr_cols + col]);
}

static bool set_val(void)
{
    if (!ensure_direction())
        return false;
    ret[idx++] = matrix[row][col];
    visited[row * nr_cols + col] = true;
    switch (direction) {
        case right:
            col++;
            break;
        case left:
            col--;
            break;
        case up:
            row--;
            break;
        case down:
            row++;
            break;
    }
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** lmatrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = matrixSize * matrixColSize[0];
    ret = (int *)malloc(sizeof(int) * *returnSize);
    visited = (bool *)calloc(*returnSize, sizeof(bool));
    matrix = lmatrix;
    nr_rows = matrixSize;
    nr_cols = matrixColSize[0];
    col = row = idx = 0;
    direction = right;
    while (set_val())
        ;
    free(visited);
    return ret;
}
