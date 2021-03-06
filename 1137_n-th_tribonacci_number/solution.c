int tribonacci(int n){
    static int *cache = NULL;
    if (cache == NULL)
        cache = (int *)calloc(38, sizeof(int));
    if (cache[n] != 0)
        return cache[n];
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    cache[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    return cache[n];
}
