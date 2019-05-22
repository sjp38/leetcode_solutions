struct node {
    int id;
    struct node **childs;
    int nr_childs;
    int visited;
};

void add_child(struct node *n, struct node *c) {
    n->nr_childs++;
    n->childs = realloc(n->childs, sizeof(struct node *) * n->nr_childs);
    n->childs[n->nr_childs - 1] = c;
}

bool cycle_exists(struct node *n) {
    int i;
    
    //printf("visit %d\n", n->id);
    if (n->visited) {
        //printf("visited!\n");
        n->visited = 0;
        return true;
    }
    n->visited = 1;
    for (i = 0; i < n->nr_childs; i++) {
        if (cycle_exists(n->childs[i])) {
            n->visited = 0;
            return true;
        }
    }
    n->visited = 0;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    struct node *nodes, *n;
    int i;
    
    nodes = (struct node *)malloc(sizeof(struct node) * numCourses);
    for (i = 0; i < numCourses; i++) {
        n = &nodes[i];
        n->id = i;
        n->childs = NULL;
        n->nr_childs = 0;
        n->visited = 0;
    }
    
    for (i = 0; i < prerequisitesSize; i++)
        add_child(&nodes[prerequisites[i][0]], &nodes[prerequisites[i][1]]);
    
    for (i = 0; i < numCourses; i++) {
        //printf("check %d\n", i);
        if (cycle_exists(&nodes[i]))
            return false;
    }
    return true;
}
