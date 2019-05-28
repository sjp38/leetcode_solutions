int reverse(int x){
    long val = x;
    long reversed = 0;
    unsigned max = INT_MAX;
    
    if (x < 0) {
        val = val * -1;
        max = 1U << 31;
    }
    while (val) {
        reversed = reversed * 10 + val % 10;
        if (reversed >= max)
            return 0;
        val = val / 10;
    }
    if (x < 0)
        reversed *= -1;
    return reversed;
}
