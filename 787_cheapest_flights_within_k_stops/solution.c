int min_cost;

struct node {
    int src;
    int *dsts;
    int *costs;
    int nr_dsts;
    int cap_dsts;
};

void init_node(struct node *node, int src)
{
    node->src = src;
    node->nr_dsts = 0;
    node->cap_dsts = 100;
    node->dsts = (int *)malloc(sizeof(int) * node->cap_dsts);
    node->costs = (int *)malloc(sizeof(int) * node->cap_dsts);
}

void add_dst(struct node *node, int dst, int cost)
{
    if (node->nr_dsts == node->cap_dsts) {
        node->nr_dsts *= 2;
        node->dsts = (int *)realloc(node->dsts, sizeof(int) * node->nr_dsts);
        node->costs = (int *)realloc(node->costs, sizeof(int) * node->nr_dsts);
    }
    node->dsts[node->nr_dsts] = dst;
    node->costs[node->nr_dsts++] = cost;
}

void form_structs(struct node *nodes, int nr_nodes, int **flights, int nr_flights)
{
    int i, j;
    struct node *n;
    for (i = 0; i < nr_nodes; i++) {
        n = &nodes[i];
        init_node(n, i);
        for (j = 0; j < nr_flights; j++) {
            if (flights[j][0] != i)
                continue;
            add_dst(n, flights[j][1], flights[j][2]);
        }
    }
}

void travel(int src, int dst, int K, int cost, struct node *nodes, int nr_nodes)
{
    int i, newcost;
    struct node *node;
    if (K < 0)
        return;
    node = &nodes[src];
    for (i = 0; i < node->nr_dsts; i++) {
        newcost = cost + node->costs[i];
        if (min_cost != -1 && min_cost < newcost)
            continue;
        if (node->dsts[i] == dst) {
            if (min_cost == -1 || min_cost > newcost)
                min_cost = newcost;
        } else {
            travel(node->dsts[i], dst, K - 1, newcost, nodes, nr_nodes);
        }
    }
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K){
    struct node nodes[n];
    form_structs(nodes, n, flights, flightsSize);
    /* do breadth first search */
    min_cost = -1;
    travel(src, dst, K, 0, nodes, n);
    return min_cost;
}
