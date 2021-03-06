typedef struct {
    int *cur;
    int sz_arr;
    int offset;
} RLEIterator;


RLEIterator* rLEIteratorCreate(int* A, int ASize) {
    RLEIterator *ret;
    ret = (RLEIterator *)malloc(sizeof(RLEIterator));
    ret->cur = A;
    ret->sz_arr = ASize;
    ret->offset = 0;
    return ret;
}

int rLEIteratorNext(RLEIterator* obj, int n) {
    int i;
    int remaining_nrs;
    while (n && obj->sz_arr) {
        remaining_nrs = obj->cur[0] - obj->offset;
        if (remaining_nrs > n) {
            obj->offset += n;
            return obj->cur[1];
        } else {
            obj->cur += 2;
            obj->sz_arr -= 2;
            obj->offset = 0;
            if (n > remaining_nrs) {
                n -= remaining_nrs;
                continue;
            }
            return obj->cur[-1];
        }
    }
    return -1;
}

void rLEIteratorFree(RLEIterator* obj) {
    free(obj);
}

/**
 * Your RLEIterator struct will be instantiated and called as such:
 * RLEIterator* obj = rLEIteratorCreate(A, ASize);
 * int param_1 = rLEIteratorNext(obj, n);
 
 * rLEIteratorFree(obj);
*/
