struct lru_object {
    int key;
    int val;
    struct lru_object *prev;
    struct lru_object *next;
};

typedef struct {
    int cap;
    int nr_objs;
    struct lru_object head;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *cache;
    cache = (LRUCache *)malloc(sizeof(LRUCache));
    cache->cap = capacity;
    cache->nr_objs = 0;
    cache->head.next = &cache->head;
    cache->head.prev = &cache->head;
    return cache;
}

static inline void list_remove(struct lru_object *obj)
{
    obj->next->prev = obj->prev;
    obj->prev->next = obj->next;
}
    
static inline void list_add(struct lru_object *obj, struct lru_object *prev, struct lru_object *next)
{
    obj->next = next;
    obj->prev = prev;
    next->prev = obj;
    prev->next = obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    struct lru_object *o, *head;
    head = &obj->head;
    for (o = head->next; o != head; o = o->next) {
        if (o->key == key) {
            list_remove(o);
            list_add(o, head, head->next);
            return o->val;
        }
    }
    return -1;
}

bool lRUCacheExist(LRUCache *obj, int key) {
    struct lru_object *o, *head;
    head = &obj->head;
    for (o = head->next; o != head; o = o->next) {
        if (o->key == key)
            return true;
    }
    return false;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    struct lru_object *o, *head, *victim;
    head = &obj->head;
    for (o = head->next; o != head; o = o->next) {
        if (o->key == key) {
            o->val = value;
            list_remove(o);
            list_add(o, head, head->next);
            return;
        }
    }
    o = (struct lru_object *)malloc(sizeof(struct lru_object));
    o->key = key;
    o->val = value;
    if (obj->nr_objs == obj->cap) {
        victim = head->prev;
        victim->next->prev = victim->prev;
        victim->prev->next = victim->next;
        obj->nr_objs--;
    }
    list_add(o, head, head->next);
    obj->nr_objs++;
}

void lRUCacheFree(LRUCache* obj) {
    struct lru_object *o, *next, *head;
    head = &obj->head;
    for (o = head->next, next = o->next; o != head; o = next, next = o->next) {
        free(o);
    }
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
