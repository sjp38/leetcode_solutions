int get_min_dist(int pos, int *seats, int nr_seats)
{
    int left_dist, right_dist, i;
    
    for (i = pos, left_dist = 0; i >= 0 && seats[i] == 0; i--, left_dist++)
        ;
    for (i = pos, right_dist = 0; i < nr_seats && seats[i] == 0; i++, right_dist++)
        ;
    if (pos == 0)
        return right_dist;
    if (pos == nr_seats - 1)
        return left_dist;
    return left_dist < right_dist ? left_dist : right_dist;
}

int maxDistToClosest(int* seats, int seatsSize){
    int dist, max_dist = 0;
    int i;
    for (i = 0; i < seatsSize; i++) {
        if (seats[i] == 1)
            continue;
        dist = get_min_dist(i, seats, seatsSize);
        if (dist > max_dist)
            max_dist = dist;
    }
    return max_dist;
}
