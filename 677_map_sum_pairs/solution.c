


typedef struct {
    char **keys;
    int *vals;
    int nr_pairs;
    int cap;
} MapSum;

/** Initialize your data structure here. */

MapSum* mapSumCreate() {
    MapSum *map;
    map = (MapSum *)malloc(sizeof(MapSum));
    map->cap = 100;
    map->keys = (char **)malloc(sizeof(char *) * map->cap);
    map->vals = (int *)malloc(sizeof(int) * map->cap);
    map->nr_pairs = 0;
    return map;
}

void mapSumInsert(MapSum* obj, char * key, int val) {
    int i;
    for (i = 0; i < obj->nr_pairs; i++) {
        if (strcmp(obj->keys[i], key))
            continue;
        obj->vals[i] = val;
        return;
    }
    if (obj->nr_pairs == obj->cap) {
        obj->cap *= 2;
        obj->keys = (char **)realloc(obj->keys, sizeof(char *) * obj->cap);
        obj->vals = (int *)realloc(obj->vals, sizeof(int) * obj->cap);
    }
    obj->keys[obj->nr_pairs] = key;
    obj->vals[obj->nr_pairs++] = val;
}

int mapSumSum(MapSum* obj, char * prefix) {
    int i;
    int sum = 0;
    for (i = 0; i < obj->nr_pairs; i++) {
        if (!strncmp(obj->keys[i], prefix, strlen(prefix)))
            sum += obj->vals[i];
    }
    return sum;
}

void mapSumFree(MapSum* obj) {
    free(obj->keys);
    free(obj->vals);
    free(obj);
    
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);
 
 * int param_2 = mapSumSum(obj, prefix);
 
 * mapSumFree(obj);
*/
