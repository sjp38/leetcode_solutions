/* We could further clean up using struct graph */
int **edges;
int nr_edges;

int nr_nodes;
int **childs;
int *nr_childs;
int *cap_childs;
int *visited;

#define nr_childs_of(n) (nr_childs[n])
#define nth_child_of(node, n) (childs[node][n])
#define is_visited(n) (visited[n] == 1)
#define set_visited(n) do {visited[n] = 1;} while (0)
#define clear_visited(n) do {visited[n] = 0;} while (0)

static inline bool cycle_exists2(int n) {
    int i;
    
    if (is_visited(n)) {
        clear_visited(n);
        return true;
    }
    set_visited(n);
    for (i = 0; i < nr_childs_of(n); i++) {
        if (cycle_exists2(nth_child_of(n, i))) {
            clear_visited(n);
            return true;
        }
    }
    clear_visited(n);
    return false;
}

void add_child(int n, int c) {
    nr_childs[n]++;
    if (cap_childs[n] < nr_childs[n]) {
        cap_childs[n] = nr_childs[n] * 2;
        childs[n] = realloc(childs[n], sizeof(int) * cap_childs[n]);
    }
    childs[n][nr_childs[n] - 1] = c;
}

/* initialize 'childs', 'nr_childs', and 'visited' */
void construct_graph(void) {
    int n, c;
    int i;
    
    visited = (int *)calloc(nr_nodes, sizeof(int));
    cap_childs = (int *)calloc(nr_nodes, sizeof(int));
    nr_childs = (int *)calloc(nr_nodes, sizeof(int));
    childs = (int **)calloc(nr_nodes, sizeof(int *));
    
    for (i = 0; i < nr_edges; i++) {
        n = edges[i][0];
        c = edges[i][1];
        add_child(n, c);
    }
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int i;
    
    edges = prerequisites;
    nr_edges = prerequisitesSize;
    nr_nodes = numCourses;
    
    construct_graph();
    
    /* if any cycle exists, we cannot finish whole courses */
    for (i = 0; i < numCourses; i++) {
        if (cycle_exists2(i))
            return false;
    }
    return true;
}
