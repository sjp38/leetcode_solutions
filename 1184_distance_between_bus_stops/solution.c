int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int cw_dist = 0, total_dist = 0;
    int tmp;
    int i;
    if (start > destination) {
        tmp = start;
        start = destination;
        destination = tmp;
    }
    for (i = 0; i < distanceSize; i++) {
        total_dist += distance[i];
        if (i >= start && i < destination)
            cw_dist += distance[i];
    }
    if (cw_dist * 2 < total_dist)
        return cw_dist;
    return total_dist - cw_dist;
}
