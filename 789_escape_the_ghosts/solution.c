#define __diff(x, y) (x > y? x - y : y - x)

#define diff(x1, y1, x2, y2) (__diff(x1, x2) + __diff(y1, y2))

bool escapeGhosts(int** ghosts, int ghostsSize, int* ghostsColSize, int* target, int targetSize){
    int to_go;
    int i;
    to_go = diff(0, 0, target[0], target[1]);
    for (i = 0; i < ghostsSize; i++) {
        if (diff(target[0], target[1], ghosts[i][0], ghosts[i][1]) <= to_go)
            return false;
    }
    return true;
}
