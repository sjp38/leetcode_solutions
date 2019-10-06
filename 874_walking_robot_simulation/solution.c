int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize){
    int coord[2] = {0,};
    int next_coord[2];
    int direction = 0;  /* in clockwise.  0: north, 1: east, 2: south, 3: west */
    int cmd;
    int *obstacle;
    int distance, max_distance = 0;
    int i, j;
    
    for (i = 0; i < commandsSize; i++) {
        cmd = commands[i];
        if (cmd == -1) {
            direction = (direction + 1) % 4;
            continue;
        } else if (cmd == -2) {
            direction = (direction + 4 - 1) % 4;
            continue;
        }
        next_coord[0] = coord[0];
        next_coord[1] = coord[1];
        if (direction == 0)
            next_coord[1] = coord[1] + cmd;
        else if (direction == 1)
            next_coord[0] = coord[0] + cmd;
        else if (direction == 2)
            next_coord[1] = coord[1] - cmd;
        else if (direction == 3)
            next_coord[0] = coord[0] - cmd;
        else
            printf("Wrong direction %d\n", direction);
        
        for (j = 0; j < obstaclesSize; j++) {
            obstacle = obstacles[j];
            if (coord[1] == obstacle[1]) {
                if (coord[0] < obstacle[0] && obstacle[0] <= next_coord[0])
                    next_coord[0] = obstacle[0] - 1;
                else if (next_coord[0] <= obstacle[0] && obstacle[0] < coord[0])
                    next_coord[0] = obstacle[0] + 1;
            } else if (coord[0] == obstacle[0]) {
                if (coord[1] < obstacle[1] && obstacle[1] <= next_coord[1])
                    next_coord[1] = obstacle[1] - 1;
                else if (next_coord[1] <= obstacle[1] && obstacle[1] < coord[1])
                    next_coord[1] = obstacle[1] + 1;
            }
        }
        coord[0] = next_coord[0];
        coord[1] = next_coord[1];
        distance = coord[0] * coord[0] + coord[1] * coord[1];
        if (distance > max_distance)
            max_distance = distance;
    }
    return max_distance;
}
