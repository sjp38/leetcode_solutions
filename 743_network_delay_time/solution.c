struct node {
    int val;
    struct node *neighbors[100];
    int times[100];
    int nr_neighbors;
};

struct node nodes[100];
int answers[100];

void update_time(int dst, int time)
{
    struct node *node;
    int i;
    int dst_idx;
    dst_idx = dst - 1;
    if (answers[dst_idx] != -1 && time >= answers[dst_idx])
        return;
    answers[dst_idx] = time;
    node = &nodes[dst_idx];
    for (i = 0; i < node->nr_neighbors; i++) {
        update_time(node->neighbors[i]->val, time + node->times[i]);
    }
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K){
    struct node *node, *snode, *dnode;
    int src, dst;
    int i, j;
    
    for (i = 0; i < N; i++) {
        node = &nodes[i];
        node->val = i + 1;
        node->nr_neighbors = 0;
    }
    for (i = 0; i < timesSize; i++) {
        snode = &nodes[times[i][0] - 1];
        dnode = &nodes[times[i][1] - 1];
        snode->neighbors[snode->nr_neighbors] = dnode;
        snode->times[snode->nr_neighbors++] = times[i][2];
    }
    
    int answer = 0;
    
    for (i = 0; i < N; i++)
        answers[i] = -1;
    
    update_time(K, 0);
    
    for (i = 0; i < N; i++) {
        if (answers[i] == -1)
            return -1;
        if (answers[i] > answer)
            answer = answers[i];
    }
    return answer;
}
