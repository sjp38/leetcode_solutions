struct square {
    int l;
    int b;
    int r;
    int t;
};

bool intersect(struct square *a, struct square *b, struct square *ret)
{
    struct square *l, *r;
    struct square *lower, *upper;
    
    if (a->r <= b->l || b->r <= a->l || a->t <= b->b || b->t <= a->b)
        return false;
    
    l = a, r = b;
    if (b->l < a->l)
        l = b, r = a;
    lower = a, upper = b;
    if (b->b < a->b)
        lower = b, upper = a;
    ret->l = r->l;
    ret->r = l->r < r->r ? l->r : r->r;
    ret->b = upper->b;
    ret->t = lower->t < upper->t ? lower->t : upper->t;
    return true;
}

static inline unsigned long sz_rec(struct square *r)
{
    return ((r->r - r->l) * (r->t - r->b));
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    struct square a, b, inter;
    int sz_inter = 0;
    
    a.l = A, a.b = B, a.r = C, a.t = D;
    b.l = E, b.b = F, b.r = G, b.t = H;
    
    if (intersect(&a, &b, &inter))
        sz_inter = sz_rec(&inter);
    return sz_rec(&a) + sz_rec(&b) - sz_inter;
}
