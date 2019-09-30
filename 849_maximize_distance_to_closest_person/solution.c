int maxDistToClosest(int* seats, int seatsSize){
    int dist = 0, max_dist = 0, lp = -1;
    int i;
    for (i = 0; i < seatsSize; i++) {
        if (seats[i] == 0) {
            dist++;
            continue;
        } else {
            if (dist > 0) {
                if (lp != -1) {
                    dist = (dist + 1) / 2;
                }
                if (dist > max_dist)
                    max_dist = dist;
                dist = 0;
            }
            lp = i;
        }
    }
    if (lp == -1)
        return dist;
    if (seats[seatsSize - 1] == 0 && dist > max_dist) {
        max_dist = dist;
    }
    return max_dist;
}
