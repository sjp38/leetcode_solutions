typedef struct {
    int *prices;
    int *spans;
    int nr_prices;
    int cap_prices;
    int min_span;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner *ret;
    ret = malloc(sizeof(StockSpanner));
    ret->cap_prices = 100;
    ret->nr_prices = 0;
    ret->prices = (int *)malloc(sizeof(int) * ret->cap_prices);
    ret->spans = (int *)malloc(sizeof(int) * ret->cap_prices);
    ret->min_span = 0;
    return ret;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int i, ret;
    if (obj->nr_prices == obj->cap_prices) {
        obj->cap_prices *= 2;
        obj->prices = (int *)realloc(obj->prices, sizeof(int) * obj->cap_prices);
        obj->spans = (int *)realloc(obj->spans, sizeof(int) * obj->cap_prices);
    }
    obj->prices[obj->nr_prices++] = price;
    for (i = obj->nr_prices - 2, ret = 1; i >= 0;) {
        if (obj->prices[i] > price)
            break;
        ret += obj->spans[i];
        i -= obj->spans[i];
    }
    obj->spans[obj->nr_prices - 1] = ret;
    return ret;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->prices);
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/
