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

int lRUCacheGet(LRUCache* obj, int key) {
    struct lru_object *o, *head;
    head = &obj->head;
    for (o = head->next; o != head; o = o->next) {
        if (o->key == key) {
            /* delte o */
            o->next->prev = o->prev;
            o->prev->next = o->next;
            /* insert o between head and head->next */
            o->next = head->next;
            o->prev = head;
            head->next->prev = o;
            head->next = o;
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
            /* delte o */
            o->next->prev = o->prev;
            o->prev->next = o->next;
            /* insert o between head and head->next */
            o->next = head->next;
            o->prev = head;
            head->next->prev = o;
            head->next = o;
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
    o->next = head->next;
    o->prev = head;
    head->next->prev = o;
    head->next = o;
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
